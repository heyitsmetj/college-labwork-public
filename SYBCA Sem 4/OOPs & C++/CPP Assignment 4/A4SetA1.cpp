#include <iostream>
using namespace std;

class Array
{
private:
    int *arr;
    int size;

public:
    Array(int s)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            cout << "Enter element[" << i + 1 << "]: ";
            cin >> arr[i];
        }
    }

    void bubbleSort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void findMedian()
    {
        bubbleSort();
        if (size % 2 == 0)
        {
            float median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
            cout << "Median: " << median << endl;
        }
        else
        {
            cout << "Median: " << arr[size / 2] << endl;
        }
    }

    ~Array()
    {
        delete[] arr;
    }
};

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    Array arrObj(size);
    arrObj.findMedian();
    return 0;
}
