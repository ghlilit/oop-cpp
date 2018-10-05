
/* Takes input a line of “*” of length 3k,
where k is a nonnegative integer, such that it recursively removes the middle third of
each line segment of “*”s. The algorithm stops when each segment consists of exactly one “*”.
The figure below shows an output example for k = 3.*/

#include <iostream>
#include <string>
using namespace std;

//multiplies given string with the given int times
string multiply(int n, string s) {
    string copy = s;
    for (int i = 1; i < n; i++) {
        s = s + copy;
    }
    return s;
}

//finds the first occurence of space, if not returns the length of the string
int finding(string str) {
    int num;
    num = str.find(" ");
    if (num == -1) {
        num = str.length();
    }
    return num;
}

string removal(string str) {
    int len = str.length(); //length of the function
    int index = finding(str); //finding at which index is the first space character, this helps to see where we are in process
    string spaces = multiply(index / 3, " "); //how many spaces we need to add at given indices
    cout << str + "\n";
    //base case when the space is at index 1
    if (index == 1) {
        return str;
    }
    //loops over the string, replaces the stars with spaces at given indices,prints it, calls the function again
    else {
        /*we start at 1/3-th of the index where we found the space, Ex. if the first space is at index 9, we start at index 3,
         replace the next 3 characters with spaces, then replace three starting from 9, this goes on until the end of the string */
        for (int i = index / 3; i < len; i = i + (index / 3) * 2) {
            /*builtin function, takes the index of the first element it needs to replace,
            the number of characters it needs to erase, and the string it needs to replace with*/
            str.replace(i, index / 3, spaces);
        }
        //We keep doing until the second character is not a space (base case)
        str = removal(str);
        return str;
    }
}
int main() {
    string str = "***************************";
    removal(str);
}
