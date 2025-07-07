#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
private:
    int Emp_no;
    char Name[20];
    float Basic, DA, HRA, Allowances;

public:
    void accept_details() 
    {
        cout << "Enter Employee Number: ";
        cin >> Emp_no;
        cout << "Enter Employee Name: ";
        cin >> Name;
        cout << "Enter Basic Salary: ";
        cin >> Basic;
        cout << "Enter Dearness Allowance (%): ";
        cin >> DA;
        cout << "Enter House Rent Allowance (%): ";
        cin >> HRA;
        cout << "Enter Other Allowances: ";
        cin >> Allowances;
    }

void display() 
{
        float gross_salary = Basic + DA + HRA + Allowances;

        cout << fixed << setprecision(2);
        
        cout << "\nEmployee Pay Slip\n";
        cout << "-----------------------------------\n";
        cout << left << setw(20) << "Employee Number:" << Emp_no << endl;
        cout << left << setw(20) << "Employee Name:" << Name << endl;
        cout << left << setw(20) << "Basic Salary:" << Basic << endl;
        cout << left << setw(20) << "DA (25%):" << DA << endl;
        cout << left << setw(20) << "HRA (30%):" << HRA << endl;
        cout << left << setw(20) << "Allowances:" << Allowances << endl;
        cout << left << setw(20) << "Gross Salary:" << gross_salary << endl;
        cout << "-----------------------------------\n";
    }
};

int main() 
{
    Employee emp;
    emp.accept_details();
    emp.display();
    return 0;
}