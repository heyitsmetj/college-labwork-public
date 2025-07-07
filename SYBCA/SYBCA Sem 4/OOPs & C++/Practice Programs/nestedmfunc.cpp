#include<iostream>
using namespace std;

class set
{
    int m, n;
    int largest();
    
    public:
    void input();
    void display();

};

int set::largest()                                                                    
{
    if(m >= n)
        return m;
    else
        return n;
}

void set::input()
{
    cout << "\nInput value of m: ";
    cin >> m;
    cout << "\nInput value of n: ";
    cin >> n;
}

void set::display()
{
    cout << "\nLargest value = " << largest() << endl;
}

int main()
{
    set A;
    A.input();
    A.display();
    
    return 0;
}