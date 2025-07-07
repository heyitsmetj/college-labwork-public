#include <iostream>
#include <cmath>
using namespace std;

class Cylinder{
    float radius;
    float height;
    const float PI = 3.14159;
    
    public:
        void setradius()
        {
            cout << "\nEnter the radius of the cylinder: ";
            cin >> radius;
        }
        
        void setheight()
        {
            cout << "\nEnter the height of the cylinder: ";
            cin >> height;
        }
        
        float volume()
        {
            return PI * pow(radius,2) * height;
        }
        
        float area()
        {
            return 2.0 * (PI * radius * height) + 2.0 * (PI * pow(radius, 2));
        }
};

int main() {
    Cylinder c1;
    Cylinder c2;
    
    cout << "\n Cylinder 1:" << endl;
    
    c1.setradius();
    c1.setheight();
    
    cout << "\nVolume of Cylinder 1: " << c1.volume();
    cout << "\nArea of Cylinder 1: " << c1.area() << endl;
    
    cout << "\n Cylinder 2:" << endl;
    
    c2.setradius();
    c2.setheight();
    
    cout << "\nVolume of Cylinder 2: " << c2.volume();
    cout << "\nArea of Cylinder 2: " << c2.area() << endl;
    
    return 0;
}