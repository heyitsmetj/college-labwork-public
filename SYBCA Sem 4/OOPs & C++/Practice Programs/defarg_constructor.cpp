#include<iostream>
using namespace std;

class Area
{
    int l, b, area;

    public:

    Area(int m, int n = 5);

    void calculate();

    void display()
    {
        cout << "Area of Rectangle: " << area << endl;
    }
};

Area::Area(int m, int n)
{
    l = m;
    b = n;
}

void Area::calculate()
{
    area = l * b;
}

int main()
{

    int length, breadth;

    cout << "\nEnter length: ";
    cin >> length;

    cout << "\nEnter breadth: ";
    cin >> breadth;

    Area A1(length, breadth);
    A1.calculate();

    cout << "\nObject A1: ";
    A1.display();

    Area A2(length);
    A2.calculate();

    cout << "\nObject A1: ";
    A2.display();

    return 0;
}