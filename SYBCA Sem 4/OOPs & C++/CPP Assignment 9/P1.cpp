#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream outf("Item.txt");
    string name;
    float cost;

    cout << "Enter Name of Item: ";
    cin >> name;

    outf << name << "\n";

    cout << "Enter Cost of Item: ";
    cin >> cost;

    outf << cost << "\n";

    outf.close();

    ifstream inf("Item.txt");

    inf >> name;

    inf >> cost;

    cout << name << cost;

    inf.close();

}