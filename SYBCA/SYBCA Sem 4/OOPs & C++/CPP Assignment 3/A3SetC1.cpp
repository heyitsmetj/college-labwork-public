#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

class Worker
{
    string Worker_Name;
    int No_of_Days_worked;
    float Pay_rate;
    float salary;

    public:
        Worker()
        {
            Worker_Name = "New_Worker";
            No_of_Days_worked = 00;
            Pay_rate = 00;
            calcsal();
        }

        Worker(string name, int days, float p_rate)
        {
            Worker_Name = name;
            No_of_Days_worked = days;
            Pay_rate = p_rate;
            calcsal();
        }

        void display()
        {
            cout << fixed << left << setw(30) << "\nWorker Name: " << Worker_Name << endl;
             cout << fixed << left << setw(30) << "No. of Days Worked: " << No_of_Days_worked << endl;
             cout << fixed << left << setprecision(2) << setw(30) << "Pay Rate(%): " << Pay_rate << endl;
             cout << fixed << left << setprecision(2) << setw(30) << "Salary: " << "$" << salary << endl;

        }

        void calcsal()
        {
            salary = No_of_Days_worked * Pay_rate;
        }


};

int main() 
{
    Worker w1;
    
    string name;
    int days;
    float p_rate;

    cout << "\nEnter details of Worker (Parameterized Constructor): " << endl;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter No. of Days worked: ";
    cin >> days;
    cout << "Enter Pay Rate: ";
    cin >> p_rate;

    Worker w2(name, days, p_rate);

    Worker w3(w1);

    cout << "\nDetails of Default Constructor: " << endl;
    w1.display();
    cout << "\nDetails of Parameterized Constructor: " << endl;
    w2.display();
    cout << "\nDetails of Copy Constructor: " << endl;
    w3.display();
    
    return 0;
}