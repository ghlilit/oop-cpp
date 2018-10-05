/*This is an examole of a class taking a class as a field,
Here student takes a Date object as a field*/
#include <iostream>
    using namespace std;

class Date {
    public:
        int year, day;
    string month;
};

class Student {
    public:
        string firstName, lastName, faculty;
    Date birthday;
    Student(string n, string l, string f) {
        firstName = n;
        lastName = l;
        faculty = f;
    }
    void set_Date(int year, string month, int day) {
        birthday.year = year;
        birthday.month = month;
        birthday.day = day;

    }
    void set_Name(string newName, string newLName) {
        newName = firstName;
        newLName = lastName;
    }

    string get_birthday() {
        string syear = to_string(birthday.year);
        string sday = to_string(birthday.day);
        string returni = syear + "," + birthday.month + "-" + sday;
        return returni;
    }

    string getFirstName() {
        return firstName;
    }
    string getLastName() {
        return lastName;
    }
    void copy(Student smb) {
        firstName = smb.firstName;
        lastName = smb.lastName;
        faculty = smb.faculty;
    }
};

int main() {

}
