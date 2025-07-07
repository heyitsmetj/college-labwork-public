#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream fin(filename);

    if (!fin)
    {
        cout << "Error: No such file found!" << endl;
        return 1;
    }

    string line;
    int lcount = 0;
    cout << "Lines in the file:" << endl;

    while (getline(fin, line))
    {
        cout << line << endl;

        if (!line.empty() && (line[0] != 'A' && line[0] != 'a'))
        {
            lcount++;
        }
    }

    fin.close();

    cout << "Number of lines not starting with 'A': " << lcount << endl;

    return 0;
}
