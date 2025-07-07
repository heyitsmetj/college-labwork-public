#include<iostream>
using namespace std;

class integer
{
    int m, n;

    public:

    integer()
    {
        m = 10;
        n = 20;
    }

    void display()
    {
        cout << "\nm = " << m;
        cout << "\nm = " << n;
    }

};

int main()
{
    integer i;

    i.display();

    return 0;
}