#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *str;

public:
    String(const char *s = "")
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~String()
    {
        delete[] str;
    }

    void operator!()
    {
        for (int i = 0; str[i] != '\0'; ++i)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 'a' + 'A';
            }
            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] - 'A' + 'a';
            }
        }
    }

    char operator[](int index)
    {
        if (index >= 0 && index < strlen(str))
        {
            return str[index];
        }
        return '\0';
    }

    bool operator<(String &other)
    {
        return strlen(str) < strlen(other.str);
    }

    bool operator==(String &other)
    {
        return strcmp(str, other.str) == 0;
    }

    String operator+(String &other)
    {
        char *newStr = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        String temp(newStr);
        delete[] newStr;
        return temp;
    }

    void print()
    {
        cout << str << endl;
    }
};

int main()
{
    String s1("Hello");
    String s2("World");

    cout << "String 1: ";
    s1.print();

    cout << "String 2: ";
    s2.print();

    cout << "\nReversing the case of String 1: ";
    !s1;
    s1.print();

    cout << "\nCharacter at index 2 of String 1: " << s1[2] << endl;

    if (s1 < s2)
    {
        cout << "\nString 1 is shorter than String 2" << endl;
    }
    else
    {
        cout << "\nString 1 is not shorter than String 2" << endl;
    }

    if (s1 == s2)
    {
        cout << "\nString 1 is equal to String 2" << endl;
    }
    else
    {
        cout << "\nString 1 is not equal to String 2" << endl;
    }

    String s3 = s1 + s2;
    cout << "\nConcatenating String 1 and String 2: ";
    s3.print();

    return 0;
}
