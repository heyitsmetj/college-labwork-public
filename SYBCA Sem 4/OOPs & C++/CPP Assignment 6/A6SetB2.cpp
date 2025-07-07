#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int mat[10][10];

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                mat[i][j] = 0;
            }
        }
    }
    
    void accept()
    {
                for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << "Enter element[" << i << "][" << j << "]: ";
                cin >>mat[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(Matrix &other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator*(Matrix &other)
    {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    bool operator==(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            return false;
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (mat[i][j] != other.mat[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int rows, cols;
    cout << "Enter rows of matrices: ";
    cin >> rows;

    cout << "Enter columns of matrices: ";
    cin >> cols;
    
    Matrix matrix1(rows, cols);
    cout << "Enter Matrix 1 Elements:" << endl;
    matrix1.accept();
    
    Matrix matrix2(rows, cols);
    cout << "Enter Matrix 2 Elements:" << endl;
    matrix2.accept();

    cout << "Matrix 1:" << endl;
    matrix1.display();

    cout << "\nMatrix 2:" << endl;
    matrix2.display();

    Matrix resultAdd = matrix1 + matrix2;
    cout << "\nMatrix 1 + Matrix 2:" << endl;
    resultAdd.display();

    Matrix resultMul = matrix1 * matrix2;
    cout << "\nMatrix 1 * Matrix 2:" << endl;
    resultMul.display();

    cout << "\nMatrix 1 == Matrix 2: " << (matrix1 == matrix2 ? "True" : "False") << endl;

    return 0;
}
