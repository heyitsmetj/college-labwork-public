#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct Employee
{
    int emp_id;
    char emp_name[100];
    float emp_sal;
};

void append()
{
    ofstream out("Employees.txt", ios::app);
    Employee e;

    cout << "Enter Employee ID: ";
    cin >> e.emp_id;
    cout << "Enter Employee Name: ";
    cin >> e.emp_name;
    cout << "Enter Employee Salary: ";
    cin >> e.emp_sal;

    out << e.emp_id << " " << e.emp_name << " " << e.emp_sal << "\n";
    out.close();
}

void display()
{
    ifstream in("Employees.txt", ios::in);
    Employee e;

    while (in >> e.emp_id >> e.emp_name >> e.emp_sal)
    {
        cout << "ID: " << e.emp_id << ", Name: " << e.emp_name << ", Salary: " << e.emp_sal << endl;
    }

    in.close();
}

int main()
{
    int choice;

    while (true)
    {
        cout << "1. Append Employee\n2. Display Employees\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            append();
            break;

        case 2:
            display();
            break;

        case 3:
            cout << "Exiting..." << endl;
            exit(0);
            break;

        default:
            cout << "Invalid Choice! Try Again..." << endl;
            break;
        }
    }

    return 0;
}
