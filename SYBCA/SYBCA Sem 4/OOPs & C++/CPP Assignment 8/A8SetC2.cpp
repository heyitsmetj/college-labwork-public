#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    virtual void getData()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    virtual void displayData()
    {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }

    virtual void calculateBonus() = 0;
};

class Admin : virtual public Person
{
protected:
    float salary;

public:
    void getData() 
    {
        Person::getData();
        cout << "Enter Admin Salary: ";
        cin >> salary;
    }

    void displayData() override
    {
        Person::displayData();
        cout << "Admin Salary: " << salary << endl;
    }

    void calculateBonus() override
    {
        cout << "Admin Bonus: " << (salary * 0.10) << endl;
    }
};

class Account : virtual public Person
{
protected:
    float accountBalance;

public:
    void getData() 
    {
        Person::getData();
        cout << "Enter Account Balance: ";
        cin >> accountBalance;
    }

    void displayData() 
    {
        Person::displayData();
        cout << "Account Balance: " << accountBalance << endl;
    }

    void calculateBonus() 
    {
        cout << "Account Bonus: " << (accountBalance * 0.05) << endl;
    }
};

class Master : public Admin, public Account
{
public:
    void getData() 
    {
        Admin::getData();
        cout << "Enter Master Salary and Account Balance: ";
        cin >> salary >> accountBalance;
    }

    void displayData() 
    {
        Admin::displayData();
        cout << "Master Account Balance: " << accountBalance << endl;
    }

    void calculateBonus() 
    {
        cout << "Master Bonus (Admin + Account): " << ((salary * 0.10) + (accountBalance * 0.05)) << endl;
    }
};

int main()
{
    Person *ptr;

    Master m;
    ptr = &m;

    cout << "\nEnter Master Employee Details:" << endl;
    ptr->getData();

    cout << "\nEmployee Details:" << endl;
    ptr->displayData();

    cout << "\nBonus Calculation:" << endl;
    ptr->calculateBonus();

    return 0;
}
