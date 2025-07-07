#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Mobile
{
    int mobile_id;
    string mobile_name;
    float mobile_price;

    public:
        Mobile(int id, const string name, float price)
        {
            mobile_id = id;
            mobile_name = name;
            mobile_price = price;
        }

        void display()
        {
            cout << "\nMobile Details:" << endl;
            cout << "\nMobile id: " << mobile_id << endl;
            cout << "Mobile Name: " << mobile_name << endl;
            cout << "Mobile Price: " << mobile_price << endl;
        }
};

int main()
{
    int id;
    string name;
    float price;

    cout << "\nEnter Mobile id: ";
    cin >> id;

    cout << "\nEnter Mobile Name: ";
    cin >> name;


    cout << "\nEnter Mobile Price: ";
    cin >> price;

    Mobile m(id, name, price);
    m.display();

    return 0;
}