#include <iostream>
using namespace std;

class Employee
{
    float salary;

public:
    Employee()
    {
        salary = 10;
    }

    void display()
    {
        cout << "Employee :" << salary << endl;
    }

    Employee operator--()
    {
        --salary;
        return *this;
    }
    Employee operator--(int)
    {
        Employee temp = *this;
        salary--;
        return temp;
    }
};

int main()
{
    Employee emp;

    cout << "Original ";
    emp.display();

    --emp;

    cout << "After Pre-Decrement ";
    emp.display();

    emp--;

    cout << "After Post-Decrement ";
    emp.display();

    return 0;
}