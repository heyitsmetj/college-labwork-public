#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream upper("upper.txt");
    ofstream lower("lower.txt");
    ofstream digits("digits.txt");
    ofstream convert("convert.txt");

    string source;

    cout << "Enter filename: ";
    cin >> source;

    ifstream fin;
    fin.open(source);

    if(!fin)
    {
        cout << "Error: No such file found!" << endl;
        exit(0);
    }

    char ch;

    while(!fin.eof())
    {
        fin.get(ch);
        cout << ch;

        if(isalpha(ch))
        {
            if(isupper(ch))
            {
                upper << ch << " ";
                convert << char(tolower(ch)) << " ";
            }

            if(islower(ch))
            {
                lower << ch << " ";
                convert << char(toupper(ch)) << " ";
            }
        }

        if(isdigit(ch))
            digits << ch << " ";

    }

    fin.close();
    upper.close();
    lower.close();
    digits.close();
    convert.close();

    char line[20];
    int N = 50;

    cout << "\n\nContent of upper.txt:" << endl;
    fin.open("upper.txt");
    while(fin)
    {
        fin.getline(line, N);
        cout << line << "\n";
    }
    fin.close();

    cout << "\n\nContent of lower.txt:" << endl;
    fin.open("lower.txt");
    while(fin)
    {
        fin.getline(line, N);
        cout << line << "\n";
    }
    fin.close();

    cout << "\n\nContent of digits.txt:" << endl;
    fin.open("digits.txt");
    while(fin)
    {
        fin.getline(line, N);
        cout << line << "\n";
    }
    fin.close();

    cout << "\n\nContent of convert.txt:" << endl;
    fin.open("convert.txt");
    while(fin)
    {
        fin.getline(line, N);
        cout << line << "\n";
    }
    fin.close();

}