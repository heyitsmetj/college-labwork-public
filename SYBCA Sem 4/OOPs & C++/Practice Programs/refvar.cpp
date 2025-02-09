#include<iostream>
using namespace std;

int main()
{
    float total = 10;

    float &sum = total;

    cout << "\nTotal = " << total << endl;
    cout << "\nSum = " << sum << endl;
    total = total + 1;

    cout << "\nTotal = " << total << endl;
    cout << "\nSum = " << sum << endl;
    sum = 0;

    cout << "\nTotal = " << total << endl;
    cout << "\nSum = " << sum << endl;

    return 0;
}