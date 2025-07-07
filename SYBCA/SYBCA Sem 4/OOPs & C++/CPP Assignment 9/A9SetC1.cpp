#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;

class Book
{
private:
    string title;
    string author;
    string isbn;

public:
    void input()
    {
        cout << "Enter Book Title: ";
        cin >> title;
        cout << "Enter Author Name: ";
        cin >> author;
        cout << "Enter ISBN: ";
        cin >> isbn;
    }

    void display() const
    {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }

    string getISBN() const { return isbn; }
    string getAuthor() const { return author; }
    string getTitle() const { return title; }

    void update()
    {
        cout << "Update Book Title: ";
        cin >> title;
        cout << "Update Author Name: ";
        cin >> author;
    }

    void setDetails(const string &t, const string &a, const string &i)
    {
        title = t;
        author = a;
        isbn = i;
    }
};

void addRecord()
{
    Book book;
    book.input();
    ofstream fout("books.txt", ios::app);
    fout << book.getTitle() << endl;
    fout << book.getAuthor() << endl;
    fout << book.getISBN() << endl;
    fout.close();
    cout << "Record added successfully!" << endl;
}

void displayRecords()
{
    ifstream fin("books.txt");
    if (!fin)
    {
        cout << "No records found!" << endl;
        return;
    }
    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
}

void deleteRecord()
{
    string isbn;
    cout << "Enter ISBN of the book to delete: ";
    cin >> isbn;

    ifstream fin("books.txt");
    Book books[MAX_BOOKS];
    int count = 0;
    string title, author, fileIsbn;

    while (getline(fin, title) && getline(fin, author) && getline(fin, fileIsbn))
    {
        if (fileIsbn != isbn && count < MAX_BOOKS)
        {
            books[count].setDetails(title, author, fileIsbn);
            count++;
        }
    }
    fin.close();

    ofstream fout("books.txt");
    for (int i = 0; i < count; i++)
    {
        fout << books[i].getTitle() << endl;
        fout << books[i].getAuthor() << endl;
        fout << books[i].getISBN() << endl;
    }
    fout.close();
    cout << "Record deleted successfully!" << endl;
}

void searchRecord()
{
    string isbn;
    cout << "Enter ISBN of the book to search: ";
    cin >> isbn;

    ifstream fin("books.txt");
    string title, author, fileIsbn;
    bool found = false;

    while (getline(fin, title) && getline(fin, author) && getline(fin, fileIsbn))
    {
        if (fileIsbn == isbn)
        {
            cout << "Record found: " << endl;
            cout << "Title: " << title << ", Author: " << author << ", ISBN: " << fileIsbn << endl;
            found = true;
            break;
        }
    }
    fin.close();

    if (!found)
    {
        cout << "Record not found!" << endl;
    }
}

void updateRecord()
{
    string isbn;
    cout << "Enter ISBN of the book to update: ";
    cin >> isbn;

    ifstream fin("books.txt");
    Book books[MAX_BOOKS];
    int count = 0;
    string title, author, fileIsbn;

    while (getline(fin, title) && getline(fin, author) && getline(fin, fileIsbn))
    {
        if (fileIsbn == isbn)
        {
            cout << "Updating record..." << endl;
            books[count].input();
        }
        else
        {
            books[count].setDetails(title, author, fileIsbn);
        }
        count++;
    }
    fin.close();

    ofstream fout("books.txt");
    for (int i = 0; i < count; i++)
    {
        fout << books[i].getTitle() << endl;
        fout << books[i].getAuthor() << endl;
        fout << books[i].getISBN() << endl;
    }
    fout.close();
    cout << "Record updated successfully!" << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add New Record\n";
        cout << "2. Display Records\n";
        cout << "3. Delete a Particular Record\n";
        cout << "4. Search a Record\n";
        cout << "5. Update a Record\n";
        cout << "6. Exit\n";
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
            deleteRecord();
            break;
        case 4:
            searchRecord();
            break;
        case 5:
            updateRecord();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
