#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Learn_Info
{
protected:
    int rollNo;
    string studName;
    string studClass;
    float percentage;

public:
    void getLearnDetails()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Student Name: ";
        cin >> studName;
        cout << "Enter Class: ";
        cin >> studClass;
        cout << "Enter Percentage: ";
        cin >> percentage;
    }

    void displayLearnDetails() const
    {
        cout << setw(10) << rollNo << setw(20) << studName << setw(10) << studClass << setw(12) << percentage;
    }
};

class Earn_Info
{
protected:
    int noOfHoursWorked;
    float chargesPerHour;

public:
    void getEarnDetails()
    {
        cout << "Enter Number of Hours Worked: ";
        cin >> noOfHoursWorked;
        cout << "Enter Charges per Hour: ";
        cin >> chargesPerHour;
    }

    void displayEarnDetails() const
    {
        cout << setw(10) << noOfHoursWorked << setw(12) << chargesPerHour;
    }

    float calculateEarnings() const
    {
        return noOfHoursWorked * chargesPerHour;
    }
};

class Earn_Learn_Info : public Learn_Info, public Earn_Info
{
private:
    float totalEarnings;

public:
    Earn_Learn_Info()
    {
        totalEarnings = 0;
    }

    void getDetails()
    {
        getLearnDetails();
        getEarnDetails();
        totalEarnings = calculateEarnings();
    }

    void displayDetails() const
    {
        displayLearnDetails();
        displayEarnDetails();
        cout << setw(12) << totalEarnings << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    Earn_Learn_Info *students = new Earn_Learn_Info[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        students[i].getDetails();
    }

    cout << "\nStudent Information with Earnings:\n";
    cout << setw(10) << "RollNo" << setw(20) << "Name" << setw(10) << "Class" << setw(12) << "Percentage"
         << setw(10) << "Hours" << setw(12) << "Rate" << setw(12) << "Total Earned" << endl;
    cout << string(86, '-') << endl;

    for (int i = 0; i < n; i++)
    {
        students[i].displayDetails();
    }

    delete[] students;
    return 0;
}
