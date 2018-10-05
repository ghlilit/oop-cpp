/*Takes an array as an input, computes the average and the number
of elements above average*/
#include <iostream>
    using namespace std;
const int length = 10;
int MyArray[length];
int input, sum, number, avg = 0;
int average();
int main() {
    for (int i = 0; i < length; i++) {
        cin >> input;
        MyArray[i] = input;
    }
    average();
    for (int i = 0; i < length; i++) {
        if (MyArray[i] > avg) {
            number++;
        }
    }
    cout << "The average number is " << avg << endl;
    cout << "The number of inputs bigger than average is " << number;
}
int average() {
    for (int i = 0; i < length; i++) {
        sum += MyArray[i];
    }
    avg = sum / length;
    return avg;
}
