#include <iostream>
using namespace std;

class StudentGPA
{
private:
    float *gpa;
    int numStudents;

public:
    StudentGPA(int n)
    {
        numStudents = n;
        gpa = new float[numStudents];
    }

    void inputGPA()
    {
        for (int i = 0; i < numStudents; i++)
        {
            cout << "Enter GPA of Student[" << i + 1 << "]: ";
            cin >> gpa[i];
        }
    }

    void displayGPA()
    {
        for (int i = 0; i < numStudents; i++)
        {
            cout << "Student " << i + 1 << ": " << gpa[i] << endl;
        }
    }

    ~StudentGPA()
    {
        delete[] gpa;
    }
};

int main()
{
    int n;
    
    cout << "Enter no. of students: "; 
    cin >> n;

    StudentGPA students(n);
    students.inputGPA();
    students.displayGPA();

    return 0;
}
