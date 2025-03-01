#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    int rollNumber;

public:
    void inputStudentDetails()
    {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNumber;
    }

    void displayStudentDetails() const
    {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

class Theory : virtual public Student
{
protected:
    int theoryMarks[5];

public:
    void inputTheoryMarks()
    {
        cout << "Enter marks for 5 theory subjects:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> theoryMarks[i];
        }
    }

    void displayTheoryMarks() const
    {
        cout << "Theory Marks: ";
        for (int i = 0; i < 5; i++)
        {
            cout << theoryMarks[i] << " ";
        }
        cout << endl;
    }
};

class Practical : virtual public Student
{
protected:
    int practicalMarks[2];

public:
    void inputPracticalMarks()
    {
        cout << "Enter marks for 2 practical subjects:" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "Practical " << i + 1 << ": ";
            cin >> practicalMarks[i];
        }
    }

    void displayPracticalMarks() const
    {
        cout << "Practical Marks: ";
        for (int i = 0; i < 2; i++)
        {
            cout << practicalMarks[i] << " ";
        }
        cout << endl;
    }
};

class Result : public Theory, public Practical
{
protected:
    int total_marks;
    string student_class;

public:
    void calculateTotalMarks()
    {
        total_marks = 0;
        for (int i = 0; i < 5; i++)
        {
            total_marks += theoryMarks[i];
        }
        for (int i = 0; i < 2; i++)
        {
            total_marks += practicalMarks[i];
        }
    }

    void displayTotalMarks() const
    {
        cout << "Total Marks: " << total_marks << endl;
    }

    void inputClass()
    {
        cout << "Enter student class: ";
        cin >> student_class;
    }

    void displayClass() const
    {
        cout << "Class: " << student_class << endl;
    }
};

int main()
{
    Result student;
    
    student.inputStudentDetails();
    student.inputTheoryMarks();
    student.inputPracticalMarks();
    student.inputClass();

    student.calculateTotalMarks();

    student.displayStudentDetails();
    student.displayTheoryMarks();
    student.displayPracticalMarks();
    student.displayTotalMarks();
    student.displayClass();

    return 0;
}
