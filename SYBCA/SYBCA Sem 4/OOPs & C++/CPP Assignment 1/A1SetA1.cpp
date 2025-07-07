#include <iostream>
using namespace std;

int main()
{
    // Floyd's triangle
    int n, count = 1;
    cout << "Enter the number of rows: ";
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        
        for (int j = 0; j < i; j++)
        {
            cout << count++ << "\t";
        }
        cout << endl;
    }

    return 0;
}