#include <iostream>
#include <string>
using namespace std;

class Date
{
    int dd;
    int mm;
    int yyyy;
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    public:
        Date(int day, int month, int year)
        {
            if(month < 1 || month > 12)
            {
                cout << "\nInvalid Month! Deafult values (01-Jan--1990) set." << endl;
                dd = 1;
                mm = 1;
                yyyy = 1900;
            }
            else
            {
                dd = day;
                mm = month;
                yyyy = year;
            }
        }
        
        void display()
        {
            cout << "\nOriginal Date: " << dd << "-" << mm << "-" << yyyy << endl;
            cout << "Formatted Date:" << dd << "-" << months[mm - 1] << "-" << yyyy << endl;
        }
};

int main() 
{
    int day, month, year;
    
    cout << "Enter the day part: ";
    cin >> day;
    
    cout << "Enter the month part: ";
    cin >> month;
    
    cout << "Enter the year part: ";
    cin >> year;
    
    Date d(day, month, year);
    
    d.display();

    return 0;
}