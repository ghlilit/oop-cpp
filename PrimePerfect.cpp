//The program finds the nedxt perfect and the next prime number of the given number
#include <iostream>
    using namespace std;
bool findprime(int);
bool findperfect(int);

int input, num, sum, primeint, perfectint = 0;
int main() {
    bool prime;
    bool perfect;
    cin >> input;

    while (true) {
        input++;
        prime = findprime(input);
        if (prime == true) {
            primeint = input;
            break;
        }
    }
    while (true) {
        input++;
        perfect = findperfect(input);
        if (perfect == true) {
            perfectint = input;
            break;
        }
    }
    cout << "Next perfect number is " << perfectint << endl;
    cout << "Next prime number is " << primeint << endl;
}

bool findprime(int num) {
    bool prime = true;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

bool findperfect(int num) {
    bool perfect = false;
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num) {
        perfect = true;
    }
    return perfect;
}
