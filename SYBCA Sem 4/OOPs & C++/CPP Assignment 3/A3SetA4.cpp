#include <iostream>
using namespace std;

class Numbers
{
    int n;
    int result;
    int sum;
    
    public:
    
    Numbers(int num)
    {
        n = num;
    }
    
    void findsum()
        {
            for(int i = 1;i <= n;i++)
            {
                int sum = 0;

                for(int j = 1; j <= i; j++)
                {
                    sum += j;
                }

                result += sum;
            }

            cout << "Sum of number between 1 and " << n << " = " << result << endl;
        }
};

int main() 
{
    int num;
    cout << "Enter a number for the series: ";
    cin >> num;
    
    Numbers n1(num);
    
    n1.findsum();

    return 0;
}