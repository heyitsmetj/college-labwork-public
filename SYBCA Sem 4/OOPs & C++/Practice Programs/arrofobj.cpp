#include<iostream>
using namespace std;

class student
{
    char name[20];
    int roll_no;
    int age;
    static int count;

    public:
    void accept();
    
    void display()
    {
        cout << "\nName: " << name << endl <<
                "Roll_no: " << roll_no << endl <<
                "Age: " << age << endl;
    }

    static void showcount()
    {
        cout << "\nCount of objects: " << count << endl;
    }
};

void student::accept()
{
    cout << "\nName: ";
    cin >> name;
    cout << "\nRoll_no: ";
    cin >> roll_no;
    cout << "\nAge: ";
    cin >> age;
    
    count++;
}

int student::count;

int main()
{
    student s[20];
    int i, n;

    cout << "\nEnter the no. of students: ";
    cin >> n;

    for(i = 0; i < n; i++)
        s[i].accept();

    for(i = 0; i < n; i++)
        s[i].display();

    student::showcount();

    return 0;
}