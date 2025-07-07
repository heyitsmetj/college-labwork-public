#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Number
{
    int num1;
    int num2;

    public:
        
        Number()
        {
            num1 = 0;
            num2 = 0;
        }

        Number(int x, int y = 0)
        {
            num1 = x;
            num2 = y;
        }

        void display()
        {
            cout << "\nNum1:" << num1 << endl;
            cout << "Num2:" << num2 << endl;
        }

        void max()
        {
            if(num1 > num2)
                cout << endl << num1 << " is greater than " << num2 << endl;
            else
                cout << endl << num2 << " is greater than " << num1 << endl;
        }
};

int main()
{
    int x, y;
    
    cout << "\nUsing default constructor(values will be 0, 0):" << endl;
    Number n1;
    n1.display();
    
    cout << "\nUsing parameterized constructor, enter both values: " << endl;
    cout << "\nEnter num1: ";
    cin >> x;
    cout << "\nEnter num2: ";
    cin >> y;
    
    Number n2(x, y);
    n2.display();
    
    cout << "\nUsing default parameter constructor with default one default value: " << endl;
    cout << "\nEnter num1: ";
    cin >> x;

    Number n3(x);
    n3.display();

    cout << "Max of object 1:";
    n1.max();

    cout << "Max of object 2:";
    n2.max();

    cout << "Max of object 3:";
    n3.max();

    return 0;
}