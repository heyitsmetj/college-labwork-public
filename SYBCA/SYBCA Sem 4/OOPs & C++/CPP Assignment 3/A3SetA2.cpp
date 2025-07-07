#include <iostream>
using namespace std;

class SI
{
    float principal;
    float rate;
    float time;

public:
    SI(float p, float t, float r = 5)
    {
        principal = p;
        time = t;
        rate = r;
    }

    float calculate()
    {
        return (principal * rate * time) / 100;
    }
};

int main()
{
    int p, r, t;

    char ch;

    cout << "Enter the principal amount: ";
    cin >> p;

    cout << "Enter the time period: ";
    cin >> t;

    cout << "Do you want to provide ROI?(Y/N): ";
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
    {
        cout << "Enter the ROI: ";
        cin >> r;
        SI o1(p,t,r);
        cout << "Simple Interest with given ROI: " << o1.calculate() << endl;
    }
    else
    {   
        SI o1(p,t);
        cout << "Simple Interest with default ROI: " << o1.calculate() << endl;
    }
    return 0;
}