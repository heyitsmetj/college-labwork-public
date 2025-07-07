#include <iostream>
using namespace std;

class Rational
{
    int numerator, denominator;
    void simplify();
    static int findGCD(int a, int b);

public:
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }

    Rational(int num, int den)
    {
        numerator = num;
        denominator = den;

        if (denominator == 0)
        {
            cout << "Error: Denominator cannot be zero. Setting denominator to 1." << endl;
            denominator = 1;
        }

        simplify();
    }

    Rational operator+(const Rational &r);
    Rational operator-(const Rational &r);
    Rational operator*(const Rational &r);
    Rational operator/(const Rational &r);

    void input();
    void display();
};

void Rational::simplify()
{
    int gcd = findGCD(numerator, denominator);

    if (gcd != 0)
    {
        numerator /= gcd;
        denominator /= gcd;
    }

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int Rational::findGCD(int a, int b)
{
    a = (a < 0 ? -a : a);
    b = (b < 0 ? -b : b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

Rational Rational::operator+(const Rational &r)
{
    int num = numerator * r.denominator + r.numerator * denominator;
    int den = denominator * r.denominator;
    return Rational(num, den);
}

Rational Rational::operator-(const Rational &r)
{
    int num = numerator * r.denominator - r.numerator * denominator;
    int den = denominator * r.denominator;
    return Rational(num, den);
}

Rational Rational::operator*(const Rational &r)
{
    int num = numerator * r.numerator;
    int den = denominator * r.denominator;
    return Rational(num, den);
}

Rational Rational::operator/(const Rational &r)
{
    if (r.numerator == 0)
    {
        cout << "Error: Division by zero rational!" << endl;
        return Rational(0, 1);
    }

    int num = numerator * r.denominator;
    int den = denominator * r.numerator;

    return Rational(num, den);
}

void Rational::input()
{
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    if (denominator == 0)
    {
        cout << "Error: Denominator cannot be zero. Setting denominator to 1." << endl;
        denominator = 1;
    }
    
    simplify();
}

void Rational::display()
{
    cout << numerator << "/" << denominator;
}

int main()
{
    Rational r1, r2;

    cout << "Enter first rational number:" << endl;
    r1.input();
    cout << "\nEnter second rational number:" << endl;
    r2.input();

    Rational sum = r1 + r2;
    Rational diff = r1 - r2;
    Rational prod = r1 * r2;
    Rational quot = r1 / r2;

    cout << "\nFirst Rational: ";
    r1.display();
    cout << "\nSecond Rational: ";
    r2.display();
    cout << "\n\nSum: ";
    sum.display();
    cout << "\nDifference: ";
    diff.display();
    cout << "\nProduct: ";
    prod.display();
    cout << "\nQuotient: ";
    quot.display();
    cout << endl;

    return 0;
}
