#include <iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    void setnum(float r, float i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex &c)
    {
        Complex temp;

        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }

    Complex operator*(const Complex &c)
    {
        Complex temp;

        temp.real = real * c.real;
        temp.imag = imag * c.imag;

        return temp;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1, c2;
    float r1, i1, r2, i2;

    cout << "Enter real part of first complex number: ";
    cin >> r1;
    cout << "Enter imaginary part of first complex number: ";
    cin >> i1;

    c1.setnum(r1, i1);

    cout << "Enter real part of second complex number: ";
    cin >> r2;
    cout << "Enter imaginary part of second complex number: ";
    cin >> i2;

    c2.setnum(r2, i2);

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "Sum: ";
    sum.display();

    cout << "Product: ";
    product.display();

    return 0;
}
