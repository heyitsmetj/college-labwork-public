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
    ofstream fout("SECOND.txt");

    if (!fin)
    {
        cout << "Error: No such file found!" << endl;
        return 1;
    }

    string word;
    cout << "Words in the file:" << endl;

    while (fin >> word)
    {
        cout << word << endl;
        char vowels[5] = {'a','e','i','o','u'};
        for(int i = 0; i < 5; i++)
        {
            if(word[0] == vowels[i])
                fout << word << " ";
        }
    }

    fin.close();
    fout.close();

    cout << "Content of SECOND.txt" << endl;
    fin.open("SECOND.txt");
    while (fin >> word)
    {
        cout << word << " ";
    }

    fin.close();

    return 0;
}
