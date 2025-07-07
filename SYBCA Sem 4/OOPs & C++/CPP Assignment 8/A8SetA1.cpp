#include <iostream>
#include <stdlib.h>
using namespace std;

class Shape
{
public:
    virtual void accept() = 0;
    virtual void display() = 0;
    virtual void area() = 0;
};

class Circle : public Shape
{
    float radius;
    float c_area;

public:
    void accept()
    {
        cout << "Enter radius of the circle: ";
        cin >> radius;
    }

    void area()
    {
        c_area = 3.14159 * radius * radius;
    }

    void display()
    {
        cout << "Shape: Circle" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << c_area << endl;
    }
};

class Rectangle : public Shape
{
    float length, breadth;
    float rect_area;

public:
    void accept()
    {
        cout << "Enter length & breadth of Rectangle: ";
        cin >> length >> breadth;
    }

    void area()
    {
        rect_area = length * breadth;
    }

    void display()
    {
        cout << "Shape: Rectangle" << endl;
        cout << "Length: " << length << ", Breadth: " << breadth << endl;
        cout << "Area: " << rect_area << endl;
    }
};

class Trapezoid : public Shape
{
    float b1, b2, height;
    float trapezoid_area;

public:
    void accept()
    {
        cout << "Enter base1, base2 & height: ";
        cin >> b1 >> b2 >> height;
    }

    void area()
    {
        trapezoid_area = 0.5 * (b1 = b2) * height;
    }

    void display()
    {
        cout << "Shape: Trapezoid" << endl;
        cout << "Base1: " << b1 << ", Base2: " << b2 << ", Height: " << height << endl;
        cout << "Area: " << trapezoid_area << endl;
    }
};

int main()
{
    int choice;
    Shape *shape;

    while (true)
    {
        cout << "\nChoose a Shape to find area:";
        cout << "\n1. Circle";
        cout << "\n2. Rectangle";
        cout << "\n3. Trapezoid";
        cout << "\n4. Exit";

        cout << "\nEnter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            shape = new Circle();
            break;
        case 2:
            shape = new Rectangle();
            break;
        case 3:
            shape = new Trapezoid();
            break;
        case 4:
            exit(1);

        default:
            cout << "\nInvalid Choice!" << endl;
            break;
        }

        shape->accept();
        shape->area();
        shape->display();

        delete shape;
    }

    return 0;
}