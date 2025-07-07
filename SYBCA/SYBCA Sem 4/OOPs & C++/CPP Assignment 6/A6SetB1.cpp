#include <iostream>
using namespace std;

class Vector
{
private:
    int x, y;

public:
    Vector(int x = 0, int y = 0) : x(x), y(y) {}

    friend int operator*( Vector &v1,  Vector &v2);
    friend ostream &operator<<(ostream &out,  Vector &v);
    friend istream &operator>>(istream &in, Vector &v);
};

int operator*( Vector &v1,  Vector &v2)
{
    return (v1.x * v2.x + v1.y * v2.y);
}

ostream &operator<<(ostream &out,  Vector &v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

istream &operator>>(istream &in, Vector &v)
{
    cout << "Enter x: ";
    in >> v.x;
    cout << "Enter y: ";
    in >> v.y;
    return in;
}

int main()
{
    Vector v1, v2;

    cout << "Enter vector 1:" << endl;
    cin >> v1;
    cout << "Enter vector 2:" << endl;
    cin >> v2;

    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;

    int dotProduct = v1 * v2;
    cout << "Dot product of the two vectors: " << dotProduct << endl;

    return 0;
}
