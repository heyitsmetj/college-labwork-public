#include <iostream>
#define MAX 5
using namespace std;

class LIST
{
public:
    virtual void store(int) = 0;
    virtual int retrieve() = 0;
};

class STACK : public LIST
{
    int arr[MAX], top;

public:
    STACK() { top = -1; }

    void store(int value)
    {
        if (top >= MAX - 1)
        {
            cout << "\nStack Overflow! Cannot store more elements." << endl;
            return;
        }

        arr[++top] = value;
        cout << "Stored " << value << " in STACK." << endl;
    }

    int retrieve()
    {
        if (top < 0)
        {
            cout << "\nStack Underflow! No elements to retrieve." << endl;
            return -1;
        }

        cout << "Retrieved " << arr[top] << " from STACK." << endl;
        return arr[top--];
    }
};

class QUEUE : public LIST
{
    int arr[MAX], front, rear;

public:
    QUEUE() { front = rear = -1; }

    void store(int value)
    {
        if (rear >= MAX - 1)
        {
            cout << "\nQueue Overflow! Cannot store more elements." << endl;
            return;
        }

        if(front == -1)
            front = 0;

        arr[++rear] = value;
        cout << "Stored " << value << " in QUEUE." << endl;
    }

    int retrieve()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nQueue Underflow! No elements to retrieve." << endl;
            return -1;
        }

        cout << "Retrieved " << arr[front] << " from QUEUE." << endl;
        return arr[front++];
    }
};

int main()
{
    STACK stack;
    QUEUE queue;
    LIST *listPtr;
    int choice, data, type;
    do
    {
        cout << "\nChoose Data Structure:";
        cout << "\n1. STACK";
        cout << "\n2. QUEUE";
        cout << "\n3. Exit";

        cout << "\nEnter your choice: ";
        cin >> type;

        if(type == 1)
            listPtr = &stack;
        else if(type == 2)
            listPtr = &queue;
        else if(type == 3)
        {
            cout << "\nExiting program." << endl;
            break;
        }
        else{
            cout << "\nInvalid choice! Try Again." << endl;
            continue;
        }

        cout << "\nOperations:";
        cout << "\n1. Store";
        cout << "\n2. Retrieve";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to store: ";
            cin >> data;
            listPtr->store(data);
            break;
        case 2:
            listPtr->retrieve();
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
            break;
        }
    }while(true);

    return 0;
}