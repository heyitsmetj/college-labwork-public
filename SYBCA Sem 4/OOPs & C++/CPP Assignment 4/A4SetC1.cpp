#include <iostream>
#include <string>

using namespace std;

class Bookshop
{
private:
    string author_name;
    string title;
    float price;
    string publisher;
    int stock;

public:
    Bookshop(const string &author, const string &t, float p, const string &publi, int st)
    {
        author_name = author ;
        title = t;
        price = p;
        publisher = publi;
        stock = st;
    }

    void displayBookDetails() const
    {
        cout << "Author: " << author_name << endl;
        cout << "Title: " << title << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
    }

    void purchaseBook(int requestedCopies)
    {
        if (requestedCopies <= stock)
        {
            float totalCost = requestedCopies * price;
            cout << "Total cost for " << requestedCopies << " copies: " << totalCost << endl;
            stock -= requestedCopies;
        }
        else
        {
            cout << "Required copies not in stock." << endl;
        }
    }
};

int main()
{
    string author = "J.K. Rowling";
    string title = "Harry Potter";
    float price = 19.99;
    string publisher = "Bloomsbury";
    int stock = 10;

    Bookshop book(author, title, price, publisher, stock);

    book.displayBookDetails();

    int requestedCopies;
    cout << "Enter the number of copies you want to purchase: ";
    cin >> requestedCopies;

    book.purchaseBook(requestedCopies);

    return 0;
}
