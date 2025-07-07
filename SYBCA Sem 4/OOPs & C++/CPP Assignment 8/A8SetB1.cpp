#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
    string name;
    int rollNumber;

public:
    Student() : rollNumber(0) {}

    virtual void getData() = 0;     
    virtual void displayData() = 0;

    virtual ~Student() {} 
};

class Engineering : public Student
{
private:
    string specialization;

public:
    void getData()
    {
        cout << "Enter Engineering Student Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Specialization: ";
        cin >> specialization;
    }

    void displayData()
    {
        cout << "\n[Engineering Student]\n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber;
        cout << "\nSpecialization: " << specialization << endl;
    }
};

class Medicine : public Student
{
private:
    string department;

public:
    void getData()
    {
        cout << "Enter Medicine Student Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Department: ";
        cin >> department;
    }

    void displayData()
    {
        cout << "\n[Medicine Student]\n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber;
        cout << "\nDepartment: " << department << endl;
    }
};

class Science : public Student
{
private:
    string researchField;

public:
    void getData()
    {
        cout << "Enter Science Student Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Research Field: ";
        cin >> researchField;
    }

    void displayData()
    {
        cout << "\n[Science Student]\n";
        cout << "Name: " << name << "\nRoll Number: " << rollNumber;
        cout << "\nResearch Field: " << researchField << endl;
    }
};

int main()
{
    int MAX_STUDENTS;
    
    cout << "Enter no. of students to input: ";
    cin >> MAX_STUDENTS;
    
    Student *students[MAX_STUDENTS];

    int choice;

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        cout << "\nSelect Student Type: \n1. Engineering \n2. Medicine \n3. Science\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            students[i] = new Engineering();
            break;
        case 2:
            students[i] = new Medicine();
            break;
        case 3:
            students[i] = new Science();
            break;
        default:
            cout << "Invalid choice! Assigning default Engineering Student.\n";
            students[i] = new Engineering();
        }
        students[i]->getData();
    }

    cout << "\nDisplaying Student Details:\n";
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        students[i]->displayData();
        delete students[i];
    }

    return 0;
}
