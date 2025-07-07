#include <iostream>
using namespace std;

class Car {
public:
    void carInfo() {
        cout << "This is a car." << endl;
    }
};

class Maruti : public Car {
public:
    void marutiInfo() {
        cout << "This is a Maruti car." << endl;
    }
};

class Maruti800 : public Maruti {
public:
    void maruti800Info() {
        cout << "This is a Maruti 800 model." << endl;
    }
};

int main() {
    Maruti800 obj;
    
    obj.carInfo();
    obj.marutiInfo();
    obj.maruti800Info();

    return 0;
}
