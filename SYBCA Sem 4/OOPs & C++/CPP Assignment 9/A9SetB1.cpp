#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string source;
    string destination;

    cout << "Enter Source filename: ";
    cin >> source;

    cout << "Enter Destination filename: ";
    cin >> destination;

    char line[20];
    int N = 20;

    // Copy Contents of original file to copy file
    ifstream fin;
    ofstream fout;
    fin.open(source);

    if(!fin)
    {
        cout << "Error: No such file found!" << endl;
        exit(0);
    }

    fout.open(destination);

    while (fin)
    {
        fin.getline(line, N);
        fout << line << "\n";
    }

    fout.close();
    fin.close();

    cout << "File Content copied successfully" << endl;

    // Show Contents of source file
    cout << "Content of source file:" << endl;
    fin.open(source);

    while (fin)
    {
        fin.getline(line, N);
        cout << line << "\n";
    }

    fin.close();

    // Show Contents of copy file
    cout << "Contents of destination file:" << endl;
    fin.open(destination);

    while (fin)
    {
        fin.getline(line, N);
        cout << line << "\n";
    }

    fin.close();

    return 0;
}