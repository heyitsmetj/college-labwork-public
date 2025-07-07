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

    string words;
    cout << "Words in the file:" << endl;

    while (fin >> words)
    {
        cout << words << endl;
    }

    fin.close();

    string word;
    int wcount = 0;

    fin.open(filename);

    cout << "Enter word to search: ";
    cin >> word;

    while (fin >> words)
    {
        cout << words << endl;
        
        if(word == words)
            wcount++;
    }

    fin.close();

    cout << "Word Count = " << wcount << endl;

    return 0;
}
