#include <iostream>
#include <iomanip>

using namespace std;

class Employee
{
public:
    string Name;
    string Designation;

    void getEmployeeDetails()
    {
        cout << "Enter Employee Name: ";
        cin >> Name;
        cout << "Enter Designation: ";
        cin >> Designation;
    }

    void displayEmployee() const
    {
        cout << setw(15) << Name << setw(15) << Designation;
    }
};

class Project
{
public:
    int Project_Id;
    string Title;

    void getProjectDetails()
    {
        cout << "Enter Project ID: ";
        cin >> Project_Id;
        cout << "Enter Project Title: ";
        cin >> Title;
    }

    void displayProject() const
    {
        cout << setw(10) << Project_Id << setw(20) << Title;
    }
};

class Emp_Proj : public Employee, public Project
{
public:
    int Duration;

    void getDetails()
    {
        getEmployeeDetails();
        getProjectDetails();
        cout << "Enter Project Duration (in months): ";
        cin >> Duration;
    }

    void displayDetails() const
    {
        displayEmployee();
        displayProject();
        cout << setw(10) << Duration << " months" << endl;
    }
};

void bubbleSort(Emp_Proj records[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (records[j].Duration > records[j + 1].Duration)
            {
                Emp_Proj temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

void displayMenu()
{
    cout << "\nMENU\n";
    cout << "1. Build Master Table\n";
    cout << "2. Display Master Table\n";
    cout << "3. Display Project Details (Sorted by Duration)\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    Emp_Proj records[100];
    int count = 0;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < 100)
            {
                records[count].getDetails();
                count++;
                cout << "Record added successfully!\n";
            }
            else
            {
                cout << "Database full! Cannot add more records.\n";
            }
            break;

        case 2:
            if (count == 0)
            {
                cout << "No records found!\n";
            }
            else
            {
                cout << "\nMaster Table:\n";
                cout << setw(15) << "Name" << setw(15) << "Designation"
                     << setw(10) << "Proj ID" << setw(20) << "Title"
                     << setw(10) << "Duration\n";
                cout << string(70, '-') << endl;

                for (int i = 0; i < count; i++)
                {
                    records[i].displayDetails();
                }
            }
            break;

        case 3:
            if (count == 0)
            {
                cout << "No records found!\n";
            }
            else
            {
                bubbleSort(records, count);
                cout << "\nProjects Sorted by Duration:\n";
                cout << setw(15) << "Name" << setw(15) << "Designation"
                     << setw(10) << "Proj ID" << setw(20) << "Title"
                     << setw(10) << "Duration\n";
                cout << string(70, '-') << endl;

                for (int i = 0; i < count; i++)
                {
                    records[i].displayDetails();
                }
            }
            break;

        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
