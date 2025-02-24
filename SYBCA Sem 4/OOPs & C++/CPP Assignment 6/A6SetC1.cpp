#include <iostream>
using namespace std;

class Fraction
{
    int numerator, denominator;
    void simplify();
    static int findGCD(int a, int b);

public:
    Fraction operator++();
    Fraction operator++(int);
    friend istream &operator>>(istream &in, Fraction &f);
    friend ostream &operator<<(ostream &out, const Fraction &f);
};

void Fraction::simplify()
{
    int gcd = findGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

int Fraction::findGCD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

Fraction Fraction::operator++()
{
    numerator += denominator;
    simplify();
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    numerator += denominator;
    simplify();
    return temp;
}

istream &operator>>(istream &din, Fraction &f)
{
    cout << "Enter Numerator: ";
    din >> f.numerator;
    cout << "Enter Denominator: ";
    din >> f.denominator;

    if (f.denominator == 0)
    {
        cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
        f.denominator = 1;
    }
    f.simplify();
    return din;
}

ostream &operator<<(ostream &dout, const Fraction &f)
{
    dout << f.numerator << "/" << f.denominator;
    return dout;
}

int main()
{
    Fraction f1, f2;

    cout << "Enter Fraction 1:" << endl;
    cin >> f1;
    cout << "\nEnter Fraction 2:" << endl;
    cin >> f2;

    cout << "\nEnter Fraction 1: " << f1 << endl;
    cout << "Enter Fraction 2: " << f2 << endl;

    ++f1;
    cout << "\nAfter Pre-Increment(f1): " << f1 << endl;

    f2++;
    cout << "After Post-Increment(f1): " << f2 << endl;

    return 0;
}