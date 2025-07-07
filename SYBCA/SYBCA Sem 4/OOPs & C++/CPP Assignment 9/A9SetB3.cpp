#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream outf("Student.txt");
    string name;
    int rollno;
    float percentage;

    cout << "Enter Roll No. of Student: ";
    cin >> rollno;

    outf << rollno << "\n";

    cout << "Enter Name of Student: ";
    cin >> name;

    outf << name << "\n";

    cout << "Enter Percentage of Student: ";
    cin >> percentage;

    outf << percentage << "\n";

    outf.close();

    ifstream inf("Student.txt");

    inf >> rollno;

    inf >> name;

    inf >> percentage;

    cout << "Roll No: " << rollno << endl 
    << "Name: " << name << endl 
    << "Percentage: " << percentage << "%" << endl;

    inf.close();

}