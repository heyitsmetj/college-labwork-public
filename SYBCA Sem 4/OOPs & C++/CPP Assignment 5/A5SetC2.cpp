#include <iostream>
using namespace std;

class DB;

class DM
{
private:
    int meters, centimeters;

public:
    DM()
    {
        meters = 0;
        centimeters = 0;
    }

    void getData()
    {
        cout << "Enter distance in meters: ";
        cin >> meters;
        cout << "Enter distance in centimeters: ";
        cin >> centimeters;
        normalize();
    }

    void display()
    {
        cout << meters << " meters " << centimeters << " centimeters\n";
    }

    void normalize()
    {
        if (centimeters >= 100)
        {
            meters += centimeters / 100;
            centimeters = centimeters % 100;
        }
    }

    friend void add(DM, DB);
};

class DB
{
private:
    int feet, inches;

public:
    DB()
    {
        feet = 0;
        inches = 0;
    }

    void getData()
    {
        cout << "Enter distance in feet: ";
        cin >> feet;
        cout << "Enter distance in inches: ";
        cin >> inches;
        normalize();
    }

    void display()
    {
        cout << feet << " feet " << inches << " inches\n";
    }

    void normalize()
    {
        if (inches >= 12)
        {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    friend void add(DM, DB);
};

void add(DM d, DB b)
{
    d.normalize();
    b.normalize();
    int totalMeters = d.meters + (b.feet * 0.3048);
    int totalCentimeters = d.centimeters + (b.inches * 2.54);

    if (totalCentimeters >= 100)
    {
        totalMeters += totalCentimeters / 100;
    }

    cout << "Total distance = " << totalMeters << " meters " << totalCentimeters << " centimeters\n";
}

int main()
{
    DM dmObj;
    DB dbObj;

    cout << "Enter data for DM object (meters and centimeters):\n";
    dmObj.getData();

    cout << "Enter data for DB object (feet and inches):\n";
    dbObj.getData();

    cout << "\nDM Object: ";
    dmObj.display();

    cout << "DB Object: ";
    dbObj.display();

    add(dmObj, dbObj);

    return 0;
}
