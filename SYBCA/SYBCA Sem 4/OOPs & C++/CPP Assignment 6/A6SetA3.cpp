#include <iostream>
using namespace std;

class Array
{
private:
    static const int MAX_SIZE = 10;
    float arr[MAX_SIZE];
    int size;

public:
    Array(int s)
    {
        size = s;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter element[" << i + 1 << "]: ";
            cin >> arr[i];
        }
    }

    void display()
    {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    friend Array &operator++(Array &a);
    friend Array operator++(Array &a, int);
    friend Array &operator--(Array &a);
    friend Array operator--(Array &a, int);
};

Array &operator++(Array &a)
{
    for (int i = 0; i < a.size; i++)
    {
        ++a.arr[i];
    }
    return a;
}

Array operator++(Array &a, int)
{
    Array temp = a;
    for (int i = 0; i < a.size; i++)
    {
        a.arr[i]++;
    }
    return temp;
}

Array &operator--(Array &a)
{
    for (int i = 0; i < a.size; i++)
    {
        --a.arr[i];
    }
    return a;
}

Array operator--(Array &a, int)
{
    Array temp = a;
    for (int i = 0; i < a.size; i++)
    {
        a.arr[i]--;
    }
    return temp;
}

int main()
{
    int size;
    cout << "Enter size of array (max: 10): ";
    cin >> size;

    Array arrObj(size);
    arrObj.display();

    ++arrObj;
    cout << "After Pre-Increment: ";
    arrObj.display();

    arrObj++;
    cout << "After Post-Increment: ";
    arrObj.display();

    --arrObj;
    cout << "After Pre-Decrement: ";
    arrObj.display();

    arrObj--;
    cout << "After Post-Decrement: ";
    arrObj.display();

    return 0;
}
