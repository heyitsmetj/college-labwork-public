#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char line[20];
    int N = 50;
    int sum = 0;

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
        if(isdigit(ch))
        {
            int digit = ch - '0';
            sum += digit;
        }
    }

    fin.close();

    // Show Contents of source file
    cout << "Content of source file:" << endl;
    fin.open(source);

    while (fin)
    {
        fin.getline(line, N);
        cout << line << "\n";
    }

    fin.close();

    cout << "Sum :"  << sum << endl;

    return 0;
}