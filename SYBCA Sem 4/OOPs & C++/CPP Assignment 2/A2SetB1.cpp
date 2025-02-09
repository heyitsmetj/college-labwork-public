#include <iostream>
using namespace std;

class Department
{
    int Dept_Id;
    string Dept_Name;
    int Establishment_year;
    int No_of_Faculty;
    int No_of_students;
    static int count;

public:

    void accept(int i)
    {
        cout << "\nEnter Department Id: ";
        cin >> Dept_Id;
        cout << "\nEnter Department Name: ";
        cin >> Dept_Name;
        cout << "\nEnter Establishment Year: ";
        cin >> Establishment_year;
        cout << "\nEnter No. of Faculty: ";
        cin >> No_of_Faculty;
        cout << "\nEnter No. of students: ";
        cin >> No_of_students;
        
        count++;
    }


    void display()
    {
        cout << "\nDepartment Id: " << Dept_Id << endl;
        cout << "Department Name: " << Dept_Name << endl;
        cout << "Establishment Year: " << Establishment_year << endl;
        cout << "No. of Faculty: " << No_of_Faculty << endl;
        cout << "No. of students: " << No_of_students << endl;
    }

    static void e_year(Department d[])
    {
        bool not_found = true;
        int year;

        cout << "\nEnter establishment year: ";
        cin >> year; 

        for(int i = 0; i < count; i++)
        {
            if(d[i].Establishment_year == year)
            {
                not_found = false;
                cout << "\nDepartment Details with Establishment Year " << year << ": " << endl; 
                d[i].display();
            }
        }

        if (not_found)
        {
            cout << "\nNo record found for the year " << year << "." << endl;
        }
        
    }

    void avail_depts(int i)
    {
        cout << i + 1 << " " << Dept_Name << endl;
    }

};

int Department::count;

int main()
{
    Department d[20];

    int i, choice, size;

    while (true)
    {
        cout << "\n1. Accept details of department(s)." << endl;
        cout << "2. Display details of a specified department." << endl;
        cout << "3. Display details of department by specific year." << endl;
        cout << "4. Exit. " << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "How many districts do you want to enter?: ";
            cin >> size;

            for (i = 0; i < size; i++)
            {
                d[i].accept(i);
            }
            break;

        case 2:
            cout << "\nAvailable Departments:" << endl;

            for (int i = 0; i < size; i++)
                d[i].avail_depts(i);

            int dist_choice;

            cout << "\nChoose corresponding index value: ";
            cin >> dist_choice;

            cout << "\nDetails of Department " << i << " : " << endl;
            d[i-1].display();
            break;
        
        case 3:
            Department::e_year(d);
            break;

        case 4:
            exit(0);
            break;
            
        default:
            cout << "\nWrong Choice! Try Again!" << endl;
            break;
        }
    }

    return 0;
}