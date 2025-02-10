#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *name;
    int length;

public:
    String(const char *str)
    {
        length = strlen(str);
        name = new char[length + 1];
        strcpy(name, str);
    }

    void combineStrings(const char *str2)
    {
        int newLength = length + strlen(str2);
        char *combined = new char[newLength + 1];

        strcpy(combined, name);
        strcat(combined, str2);

        cout << "Combined String: " << combined << endl;

        delete[] combined;
    }

    ~String()
    {
        delete[] name;
    }
};

int main()
{
    const char *str1 = "Hello";
    const char *str2 = " World!";

    String strObj1(str1);
    strObj1.combineStrings(str2);

    return 0;
}
