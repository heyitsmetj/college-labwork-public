#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

class Class2;

class Class1{
    int num;

    public:
    Class1()
    {
        num = rand() % 10;
    }

    friend void sub(Class1, Class2);
};

class Class2{
    int num;

    public:
    Class2()
    {
        num = rand() % 10;
    }

    friend void sub(Class1, Class2);
};

void sub(Class1 n1, Class2 n2)
{
   cout << "\nClass 1 Num: " << n1.num << endl;
   cout << "Class 2 Num: " << n2.num << endl;
   cout << "Result: " << n1.num - n2.num << endl;
} 

int main() 
{
    srand(time(0));
    
    Class1 n1;
    Class2 n2;
    
    sub(n1,n2);

    return 0;
}