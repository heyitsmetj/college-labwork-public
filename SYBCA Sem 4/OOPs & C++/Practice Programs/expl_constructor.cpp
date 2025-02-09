#include<iostream>
using namespace std;

class integer
{
    int m, n;

    public:

    integer(int, int);

    void display()
    {
        cout << "\nm = " << m;
        cout << "\nm = " << n;
    }

};

integer::integer(int x, int y)
{
    m = x;
    n = y;
}

int main()
{
    integer int1(0, 100);
    integer int2 = integer(25, 75);

    cout << "\nObject 1:" << endl;
    int1.display();

    cout << "\nObject 2:" << endl;
    int2.display();

    return 0;
}