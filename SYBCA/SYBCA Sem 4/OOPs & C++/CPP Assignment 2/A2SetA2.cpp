#include<iostream>
using namespace std;

class DISTANCE{
    int feet;
    int inches;

    public:
        void input()
        {
            cout << "\nEnter the ft part: ";
            cin >> feet;

            cout<< "\nEnter the inch part: ";
            cin >> inches;
            
            while (inches >= 12)
            {
                feet++;
                inches -= 12;
            }
            
        }

        void output()
        {
            cout << "\nDistance of object is " << feet << " ft " << inches << " inches." << endl;
        }

        static void sum(DISTANCE d1, DISTANCE d2)
        {
            DISTANCE result;

            result.feet = d1.feet + d2.feet;
            result.inches = d1.inches + d2.inches;

            while (result.inches >= 12)
            {
                result.feet++;
                result.inches -= 12;
            }
            
            cout << "\nSum of the two distances is " << result.feet << " ft " << result.inches << " inches." << endl;  
        }
};

int main()
{
    DISTANCE d1;
    DISTANCE d2;

    cout << "\nDistance 1:" << endl;
    
    d1.input();
    d1.output();

    cout << "\nDistance 2:" << endl;
    
    d2.input();
    d2.output();

    DISTANCE::sum(d1,d2);

    return 0;
}