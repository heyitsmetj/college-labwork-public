#include <iostream>
using namespace std;

class Matrix
{
private:
    int **arr;
    int m, n;

public:
    Matrix(int rows, int cols)
    {
        m = rows;
        n = cols;
        arr = new int *[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = new int[n];
        }

        cout << "Enter elements of the matrix (" << m << "x" << n << "):\n";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
    }

    void display()
    {
        cout << "The matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayTranspose()
    {
        cout << "Transpose of the matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < m; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main()
{
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    Matrix matrix(m, n);
    matrix.display();
    matrix.displayTranspose();

    return 0;
}
