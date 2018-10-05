//Here is an example how to use C++ pointers. The program reverses an array
#include < iostream >
    using namespace std;
//initialization
int input, n, temp;
int * dArray = new int[n];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        dArray[i] = input;
    }
    for (int i = 0; i < n / 2; i++) {
        temp = * (dArray + n - i - 1);
        *(dArray + n - i - 1) = * (dArray + i);
        *(dArray + i) = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << dArray[i] << endl;
    }
}
