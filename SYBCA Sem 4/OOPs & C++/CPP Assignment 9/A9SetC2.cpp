#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Account
{
private:
    string name;
    int accountNumber;
    double balance;

public:
    void input()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Balance: ";
        cin >> balance;
    }

    void display() const
    {
        cout << "Name: " << name << ", Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    double getBalance() const
    {
        return balance;
    }

    string getName() const
    {
        return name;
    }

    void writeToFile(ofstream &out) const
    {
        out << name << endl;
        out << accountNumber << endl;
        out << balance << endl;
    }
};

void addRecord()
{
    Account acc;
    acc.input();
    ofstream fout("accounts.txt", ios::app);
    acc.writeToFile(fout);
    fout.close();
    cout << "Record added successfully!" << endl;
}

void displayRecords()
{
    ifstream fin("accounts.txt");
    if (!fin)
    {
        cout << "No records found!" << endl;
        return;
    }
    string name;
    int accountNumber;
    double balance;

    while (getline(fin, name) && fin >> accountNumber >> balance)
    {
        fin.ignore();
        cout << "Name: " << name << ", Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
    fin.close();
}

void display10000()
{
    ifstream fin("accounts.txt");
    if (!fin)
    {
        cout << "No records found!" << endl;
        return;
    }
    string name;
    int accountNumber;
    double balance;

    cout << "Accounts with balance > 10,000:" << endl;
    while (getline(fin, name) && fin >> accountNumber >> balance)
    {
        fin.ignore();
        if (balance > 10000)
        {
            cout << "Name: " << name << endl;
        }
    }
    fin.close();
}

int main()
{
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add New Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Display Accounts with Balance > 10,000\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecords();
            break;
        case 3:
            display10000();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}
