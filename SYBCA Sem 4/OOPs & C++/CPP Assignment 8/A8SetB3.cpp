#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    int P_Code;
    string P_Name;

public:
    Person()
    {
        P_Code = 0;
        P_Name = "New_Usename";
    }

    void inputPersonDetails()
    {
        cout << "Enter Person Code: ";
        cin >> P_Code;
        cin.ignore();
        cout << "Enter Person Name: ";
        getline(cin, P_Name);
    }

    void displayPersonDetails() const
    {
        cout << "Person Code: " << P_Code << ", Name: " << P_Name << endl;
    }
};

class Account : virtual public Person
{
protected:
    int Ac_No;
    double Balance;

public:
    Account()
    {
        Ac_No = 0;
        Balance = 0.0;
    }

    void inputAccountDetails()
    {
        cout << "Enter Account Number: ";
        cin >> Ac_No;
        cout << "Enter Balance: ";
        cin >> Balance;
    }

    void displayAccountDetails() const
    {
        cout << "Account Number: " << Ac_No << ", Balance: " << Balance << endl;
    }
};

class Official : virtual public Person
{
protected:
    string Designation;
    int Experience;

public:
    Official()
    {
        Designation = "New_Designation";
        Experience = 0;
    }

    void inputOfficialDetails()
    {
        cout << "Enter Designation: ";
        cin >> Designation;
        cout << "Enter Experience (in years): ";
        cin >> Experience;
    }

    void displayOfficialDetails() const
    {
        cout << "Designation: " << Designation << ", Experience: " << Experience << " years" << endl;
    }
};

class Employee : public Account, public Official
{
public:
    void inputEmployeeDetails()
    {
        inputPersonDetails();
        inputAccountDetails();
        inputOfficialDetails();
    }

    void displayEmployeeDetails() const
    {
        displayPersonDetails();
        displayAccountDetails();
        displayOfficialDetails();
    }

    string getDesignation() const
    {
        return Designation;
    }
};

int main()
{
    const int MAX_EMPLOYEES = 5;
    Employee employees[MAX_EMPLOYEES];
    int choice, count = 0;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Build a master table for employees\n";
        cout << "2. Display a master table of employees\n";
        cout << "3. Display employees whose designation is H.O.D.\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (count < MAX_EMPLOYEES)
            {
                cout << "\nEnter details for Employee " << count + 1 << endl;
                employees[count].inputEmployeeDetails();
                count++;
            }
            else
            {
                cout << "Master table is full!" << endl;
            }
            break;
        }
        case 2:
        {
            if (count == 0)
            {
                cout << "No employee data to display!" << endl;
            }
            else
            {
                cout << "\nMaster Table of Employees:\n";
                for (int i = 0; i < count; i++)
                {
                    cout << "\nEmployee " << i + 1 << ": ";
                    employees[i].displayEmployeeDetails();
                }
            }
            break;
        }
        case 3:
        {
            bool found = false;
            if (count == 0)
            {
                cout << "No employee data to check!" << endl;
            }
            else
            {
                cout << "\nEmployees whose designation is H.O.D.:\n";
                for (int i = 0; i < count; i++)
                {
                    if (employees[i].getDesignation() == "H.O.D.")
                    {
                        employees[i].displayEmployeeDetails();
                        found = true;
                    }
                }
                if (!found)
                {
                    cout << "No employee with designation H.O.D. found." << endl;
                }
            }
            break;
        }
        case 4:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
