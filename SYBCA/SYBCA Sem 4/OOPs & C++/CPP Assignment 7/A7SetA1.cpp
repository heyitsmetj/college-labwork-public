#include <iostream>
#include <iomanip>
using namespace std;

class Product
{
private:
    int productId;
    string productName;
    double price;

public:
    Product(int id, string name, double p)
    {
        productId = id;
        productName = name;
        price = p;
    }

    double getPrice() const
    {
        return price;
    }

    string getName() const
    {
        return productName;
    }
};


class Discount : public Product
{
private:
    double discountPercentage;

public:
    Discount(int id, string name, double p, double discount)
        : Product(id, name, p), discountPercentage(discount) {}

    double calculateDiscount() const
    {
        return (getPrice() * discountPercentage) / 100;
    }

    double finalPrice() const
    {
        return getPrice() - calculateDiscount();
    }
};

int main()
{
    const int n = 3; 
    Discount products[n] = {
        Discount(1, "Product A", 100.0, 10.0),
        Discount(2, "Product B", 200.0, 15.0),
        Discount(3, "Product C", 150.0, 5.0)   
    };

    double totalPrice = 0.0;
    double totalDiscount = 0.0;

    cout << fixed << setprecision(2);
    cout << "Bill Summary:\n";
    cout << "-----------------------------------\n";
    cout << setw(10) << "ID" << setw(20) << "Product Name" << setw(10) << "Price"
         << setw(15) << "Discount" << setw(15) << "Final Price" << endl;
    cout << "-----------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        double discount = products[i].calculateDiscount();
        double finalPrice = products[i].finalPrice();

        cout << setw(10) << (i + 1)
             << setw(20) << products[i].getName()
             << setw(10) << products[i].getPrice()
             << setw(15) << discount
             << setw(10) << finalPrice << endl;

        totalPrice += products[i].getPrice();
        totalDiscount += discount;
    }

    cout << "-----------------------------------\n";
    cout << "Total Price: " << totalPrice << endl;
    cout << "Total Discount: " << totalDiscount << endl;
    cout << "Total Amount Payable: " << (totalPrice - totalDiscount) << endl;

    return 0;
}
