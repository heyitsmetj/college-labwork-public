#include<iostream>
using namespace std;

class Number{
    int num;    

    public:
        Number(){
            num = 10;
        }

        void display(){
            cout << "Number :" << num << endl;
        }

        Number operator ++(){
            ++num;
            return *this;
        } 
        Number operator ++(int){
            Number temp = *this;    
            num++;
            return temp;
        } 
};

int main()
{
    Number n;

    cout << "Original ";
    n.display();

    ++n;

    cout << "After Pre-Increment ";
    n.display();

    n++;
    
    cout << "After Post-Increment ";
    n.display();

    return 0;
}