#include <iostream>
#include <string>

using namespace std;

class Media
{
protected:
    string title;
    string publisher;
    bool isIssued;

public:
    Media() { isIssued = false; }

    virtual void getData()
    {
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Publisher: ";
        cin >> publisher;
    }

    virtual void displayData()
    {
        cout << "Title: " << title << "\nPublisher: " << publisher
             << "\nStatus: " << (isIssued ? "Issued" : "Available") << endl;
    }

    virtual void issue()
    {
        if (!isIssued)
        {
            isIssued = true;
            cout << title << " has been issued.\n";
        }
        else
        {
            cout << title << " is already issued.\n";
        }
    }

    virtual void deposit()
    {
        if (isIssued)
        {
            isIssued = false;
            cout << title << " has been returned.\n";
        }
        else
        {
            cout << title << " was not issued.\n";
        }
    }

    virtual ~Media() {}
};

class Book : public Media
{
private:
    int pageCount;

public:
    void getData()
    {
        Media::getData();
        cout << "Enter Page Count: ";
        cin >> pageCount;
    }

    void displayData()
    {
        Media::displayData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Media
{
private:
    float playTime;

public:
    void getData()
    {
        Media::getData();
        cout << "Enter Play Time (in minutes): ";
        cin >> playTime;
    }

    void displayData()
    {
        Media::displayData();
        cout << "Play Time: " << playTime << " minutes" << endl;
    }
};

int main()
{
    int MAX_ITEMS;

    cout << "Enter no. of items to store: ";
    cin >> MAX_ITEMS;

    Media *library[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do
    {
        cout << "\n*** Digital Library System ***\n";
        cout << "1. Add New Book\n";
        cout << "2. Add New Tape\n";
        cout << "3. Display All Items\n";
        cout << "4. Issue an Item\n";
        cout << "5. Return an Item\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (itemCount < MAX_ITEMS)
            {
                library[itemCount] = new Book();
                library[itemCount]->getData();
                itemCount++;
                cout << "Book added successfully!\n";
            }
            else
            {
                cout << "Library is full!\n";
            }
            break;

        case 2:
            if (itemCount < MAX_ITEMS)
            {
                library[itemCount] = new Tape();
                library[itemCount]->getData();
                itemCount++;
                cout << "Tape added successfully!\n";
            }
            else
            {
                cout << "Library is full!\n";
            }
            break;

        case 3:
            if (itemCount == 0)
            {
                cout << "Library is empty!\n";
            }
            else
            {
                cout << "\nLibrary Collection:\n";
                for (int i = 0; i < itemCount; i++)
                {
                    cout << "\nItem " << i + 1 << ":\n";
                    library[i]->displayData();
                }
            }
            break;

        case 4:
            if (itemCount == 0)
            {
                cout << "No items to issue!\n";
            }
            else
            {
                int itemNo;
                cout << "Enter item number to issue: ";
                cin >> itemNo;
                if (itemNo > 0 && itemNo <= itemCount)
                {
                    library[itemNo - 1]->issue();
                }
                else
                {
                    cout << "Invalid item number!\n";
                }
            }
            break;

        case 5:
            if (itemCount == 0)
            {
                cout << "No items to return!\n";
            }
            else
            {
                int itemNo;
                cout << "Enter item number to return: ";
                cin >> itemNo;
                if (itemNo > 0 && itemNo <= itemCount)
                {
                    library[itemNo - 1]->deposit();
                }
                else
                {
                    cout << "Invalid item number!\n";
                }
            }
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 6);

    for (int i = 0; i < itemCount; i++)
    {
        delete library[i];
    }

    return 0;
}
