#include <iostream>
using namespace std;

class PrintData
{
public:
    void print(int value)
    {
        cout << "value - " << value << endl;
    }

    void print(char *str)
    {
        cout << "value - \"" << str << "\"" << endl;
    }

    void print(int n, char *str)
    {
        cout << "value - \"";
        for (int i = 0; i < n && str[i] != '\0'; ++i)
        {
            cout << str[i];
        }
        cout << "\"" << endl;
    }
};

int main()
{
    PrintData printObj;

    printObj.print(10);

    char str[] = "Hello, World!";
    printObj.print(str);

    printObj.print(3, str);

    return 0;
}
