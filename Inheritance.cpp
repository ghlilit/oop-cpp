/*this illustrates basic OOP concepts in Cpp
Permanent and Contractos are the child classes of Employee,
Employee is a virtual class, the child classes override the calc_salary method*/
#include <iostream>
using namespace std;

class Employee {
    public:
        int get_Id() {
            return ID;
        }
    void set_salary(int s) {
        salary = s;
    }
    int get_salary() {
        return salary;
    }
    virtual void calc_salary() {
    };

    protected:
        int ID;
    int salary;
};
class Permanent: public Employee {
    public: Permanent(int h) {
        ID = h;
    }
    void set_rate(int r) {
        rate = r;
    }
    void calc_salary() {
        salary = rate * salary;
        cout << salary << endl;
    }
    private: int rate;
};

class Contractor: public Employee {
    public: Contractor(int k) {
        ID = k;
    }
    void set_days(int d) {
        days = d;
    }
    int get_days() {
        return days;
    }
    void calc_salary() {
        salary = (days / 31) * salary;
        cout << salary << endl;
    }
    private: int days;
};

int main() {
    Permanent * perm1 = new Permanent(10);
    perm1 - > set_salary(100000);
    perm1 - > set_rate(1);
    perm1 - > calc_salary();
    Contractor * cont1 = new Contractor(50);
    cont1 - > set_salary(500000);
    cont1 - > set_days(13);
    Employee ** Emps = new Employee * [2];
    Emps[0] = perm1;
    Emps[1] = cont1;
    for (int i = 0; i < 2; i++) {
        Emps[i] - > calc_salary;
    }
    return 0;
}
