#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if(n == 0 || n == 1)
    {
        return false;
    }
    else
    {
        for(int i =2;i < n; i++)
        {
            if(n % i == 0)
            return false;
        }
        
        return true;
    }
}

int main()
{
    int num;
    
    cout << "\nEnter a positive integer: ";
    cin >> num;
    
    bool flag = false;
    
    for(int i = 2; i < num;++i)
    {
        if(isPrime(i) && isPrime(num - i))
        {
            cout << i << " + " << (num - i) << " = " << num << endl;
            flag = true;
            break;
        }
    }
    
    if (!flag)
    {
        cout << num << " cannot be expressed as sum of any prime numbers." << endl;
    }
}