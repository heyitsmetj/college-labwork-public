#include <iostream>
using namespace std;

class Rectangle1;

class Rectangle2
{
private:
    int length, breadth;

public:
    Rectangle2(int l, int b) 
    {
        length = l;
        breadth = b;
    }

    friend void compareArea(Rectangle1, Rectangle2);
};

class Rectangle1
{
private:
    int length, breadth;

public:
    Rectangle1(int l, int b) 
    {
        length = l;
        breadth = b;
    }
    friend void compareArea(Rectangle1, Rectangle2);
};

void compareArea(Rectangle1 r1, Rectangle2 r2)
{
    int area1 = r1.length * r1.breadth;
    int area2 = r2.length * r2.breadth;

    if (area1 > area2)
    {
        cout << "Rectangle1 has a larger area." << endl;
    }
    else if (area1 < area2)
    {
        cout << "Rectangle2 has a larger area." << endl;
    }
    else
    {
        cout << "Both rectangles have the same area." << endl;
    }
}

int main()
{
    Rectangle1 rect1(10, 5);
    Rectangle2 rect2(8, 6);
    
    compareArea(rect1, rect2);

    return 0;
}
