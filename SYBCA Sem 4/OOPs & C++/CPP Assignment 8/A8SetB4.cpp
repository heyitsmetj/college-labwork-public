#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    int Roll_No;
    string Name;
    string Class;

public:
    Student()
    {
        Roll_No = 0;
        Name = "New_Student";
        Class = "New_Class";
    }

    void inputStudentDetails()
    {
        cout << "Enter Roll Number: ";
        cin >> Roll_No;
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter Class: ";
        cin >> Class;
    }

    void displayStudentDetails() const
    {
        cout << "Roll Number: " << Roll_No << ", Name: " << Name << ", Class: " << Class << endl;
    }
};

class Internal_Marks : virtual public Student
{
protected:
    int IntM1, IntM2, IntM3, IntM4, IntM5;

public:
    Internal_Marks() { IntM1 = IntM2 = IntM3 = IntM4 = IntM5 = 0; }

    void inputInternalMarks()
    {
        cout << "Enter Internal Marks for 5 subjects:" << endl;
        cout << "Subject 1: ";
        cin >> IntM1;
        cout << "Subject 2: ";
        cin >> IntM2;
        cout << "Subject 3: ";
        cin >> IntM3;
        cout << "Subject 4: ";
        cin >> IntM4;
        cout << "Subject 5: ";
        cin >> IntM5;
    }

    void displayInternalMarks() const
    {
        cout << "Internal Marks: " << IntM1 << " " << IntM2 << " " << IntM3 << " " << IntM4 << " " << IntM5 << endl;
    }
};

class External_Marks : virtual public Student
{
protected:
    int ExtM1, ExtM2, ExtM3, ExtM4, ExtM5;

public:
    External_Marks() { ExtM1 = ExtM2 = ExtM3 = ExtM4 = ExtM5 = 0; }

    void inputExternalMarks()
    {
        cout << "Enter External Marks for 5 subjects:" << endl;
        cout << "Subject 1: ";
        cin >> ExtM1;
        cout << "Subject 2: ";
        cin >> ExtM2;
        cout << "Subject 3: ";
        cin >> ExtM3;
        cout << "Subject 4: ";
        cin >> ExtM4;
        cout << "Subject 5: ";
        cin >> ExtM5;
    }

    void displayExternalMarks() const
    {
        cout << "External Marks: " << ExtM1 << " " << ExtM2 << " " << ExtM3 << " " << ExtM4 << " " << ExtM5 << endl;
    }
};

class Result : public Internal_Marks, public External_Marks
{
protected:
    int T1, T2, T3, T4, T5;
    bool pass[5];

public:
    Result() { T1 = T2 = T3 = T4 = T5 = 0; }

    void calculateTotalMarks()
    {
        T1 = IntM1 + ExtM1;
        T2 = IntM2 + ExtM2;
        T3 = IntM3 + ExtM3;
        T4 = IntM4 + ExtM4;
        T5 = IntM5 + ExtM5;
    }

    void checkPassFail()
    {
        pass[0] = (IntM1 >= 40 && ExtM1 >= 40);
        pass[1] = (IntM2 >= 40 && ExtM2 >= 40);
        pass[2] = (IntM3 >= 40 && ExtM3 >= 40);
        pass[3] = (IntM4 >= 40 && ExtM4 >= 40);
        pass[4] = (IntM5 >= 40 && ExtM5 >= 40);
    }

    void displayResult()
    {
        cout << "Total Marks: " << T1 << " " << T2 << " " << T3 << " " << T4 << " " << T5 << endl;
        for (int i = 0; i < 5; i++)
        {
            if (pass[i])
            {
                cout << "Subject " << i + 1 << " - Passed" << endl;
            }
            else
            {
                cout << "Subject " << i + 1 << " - Failed" << endl;
            }
        }

        bool overallPass = true;
        for (int i = 0; i < 5; i++)
        {
            if (!pass[i])
            {
                overallPass = false;
                break;
            }
        }

        if (overallPass)
        {
            cout << "Result: Passed" << endl;
        }
        else
        {
            cout << "Result: Failed" << endl;
        }
    }
};

int main()
{
    int MAX_STUDENTS;

    cout << "Enter no. of student to intake: ";
    cin >> MAX_STUDENTS;

    Result students[MAX_STUDENTS];
    int choice, count = 0;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Accept and display student details\n";
        cout << "2. Calculate Subject wise total marks obtained\n";
        cout << "3. Check pass/fail for each subject and display result\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (count < MAX_STUDENTS)
            {
                cout << "\nEnter details for Student " << count + 1 << endl;
                students[count].inputStudentDetails();
                students[count].inputInternalMarks();
                students[count].inputExternalMarks();
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
                cout << "No student data to calculate total marks!" << endl;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    students[i].calculateTotalMarks();
                    students[i].displayResult();
                }
            }
            break;
        }
        case 3:
        {
            if (count == 0)
            {
                cout << "No student data to check pass/fail!" << endl;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    students[i].checkPassFail();
                    students[i].displayResult();
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
