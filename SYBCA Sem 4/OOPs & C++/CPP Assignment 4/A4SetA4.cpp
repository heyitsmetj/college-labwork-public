#include <iostream>
using namespace std;

class PrimeChecker
{
private:
    int *number;

public:
    PrimeChecker(int num)
    {
        number = new int;
        *number = num;
    }

    void check()
    {
        int num = *number;
        if (num <= 1)
        {
            cout << num << " is not prime." << endl;
            return;
        }

        bool isPrime = true;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            cout << num << " is prime." << endl;
        }
        else
        {
            cout << num << " is not prime." << endl;
        }
    }

    ~PrimeChecker()
    {
        delete number;
    }
};

int main()
{
    int num;

    cout << "Enter number: ";
    cin >> num;
    
    PrimeChecker checker(num);
    checker.check();
    
    return 0;
}
