#include <iostream>
#include <string>
using namespace std;

class Media
{
protected:
    int id;
    string title;

public:
    Media(int id, string title)
    {
        this->id = id;
        this->title = title;
    }

    virtual void display() = 0;
};

class Book : public Media
{
private:
    string ISBN;

public:
    Book(int id, string title, string ISBN) : Media(id, title)
    {
        this->ISBN = ISBN;
    }

    void display()
    {
        cout << "Book ID: " << id << ", Title: " << title << ", ISBN: " << ISBN << endl;
    }
};

class CD : public Media
{
private:
    int dataCapacity;

public:
    CD(int id, string title, int dataCapacity) : Media(id, title)
    {
        dataCapacity = dataCapacity;
    }

    void display()
    {
        cout << "CD ID: " << id << ", Title: " << title << ", Data Capacity: " << dataCapacity << "MB" << endl;
    }
};

void acceptMedia(Media *media[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int id;
        string title;
        cout << "Enter media ID: ";
        cin >> id;
        cout << "Enter media title: ";
        cin >> title;

        int choice;
        cout << "Is it a book (1) or a CD (2)? ";
        cin >> choice;

        if (choice == 1)
        {
            string ISBN;
            cout << "Enter ISBN: ";
            cin >> ISBN;
            media[i] = new Book(id, title, ISBN);
        }
        else
        {
            int dataCapacity;
            cout << "Enter data capacity (in MB): ";
            cin >> dataCapacity;
            media[i] = new CD(id, title, dataCapacity);
        }
    }
}

void displayMedia(Media *media[], int n)
{
    cout << "\nList of all books and CDs bought:\n";
    for (int i = 0; i < n; i++)
    {
        media[i]->display();
    }
}

int main()
{
    int numItems;

    cout << "Enter no of media items to take: ";
    cin >> numItems;

    Media *media[numItems];

    acceptMedia(media, numItems);

    displayMedia(media, numItems);

    for (int i = 0; i < numItems; i++)
    {
        delete media[i];
    }

    return 0;
}
