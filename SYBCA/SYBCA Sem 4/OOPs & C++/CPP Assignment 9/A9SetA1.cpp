#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char line[20];
    int N = 50;
    int UC = 0, LC = 0, DC = 0, SC = 0;

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

        if(isalpha(ch))
        {
            if(isupper(ch))
                UC++;
            if(islower(ch))
                LC++;
        }

        if(isdigit(ch))
            DC++;
            
        if(isspace(ch))
            SC++;
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


    cout << "Lower Case Count = " << LC << "\n";
    cout << "Upper Case Count = " << UC << "\n";
    cout << "Digits Count = " << DC << "\n";
    cout << "Space Count = " << SC << "\n";

    return 0;
}