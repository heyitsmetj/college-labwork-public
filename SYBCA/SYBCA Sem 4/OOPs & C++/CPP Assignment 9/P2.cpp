#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("Country.txt");

    fout << "U.S\n";
    fout << "U.K\n";
    fout << "India\n";

    fout.close();

    fout.open("Capital.txt");

    fout << "Washington D.C\n";
    fout << "London\n";
    fout << "Delhi\n";

    fout.close();

    char line[20];
    int N = 20;
    ifstream fin;
    fin.open("Country.txt");

    while(fin)
    {
        fin.getline(line, N);
        cout << line << "\n";
    }

    fin.close();

    fin.open("Capital.txt");

    while(fin)
    {
        fin.getline(line, N);
        cout << line << "\n";
    }

    fin.close();
}