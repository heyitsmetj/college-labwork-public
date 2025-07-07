#include <iostream>
using namespace std;

class Account
{
protected:
    string Acc_Holder_Name;
    int Acc_Holder_Contact_No;

public:
    Account(string name, int contact)
    {
        Acc_Holder_Name = name;
        Acc_Holder_Contact_No = contact;
    }

    virtual void displayInfo() = 0;
    virtual void deposit(float amount) = 0;
    virtual void withdraw(float amount) = 0;
    virtual void checkBalanceAndCharge() = 0;
    virtual int getAccNo() = 0;
    virtual void calculateInterest() = 0; 
};

class Saving_Account : public Account
{
private:
    int S_Acc_No;
    float Balance;

public:
    Saving_Account(string name, int contact, int accNo, float initialBalance)
        : Account(name, contact)
    {
        S_Acc_No = accNo;
        Balance = initialBalance;
    }

    void deposit(float amount)
    {
        Balance += amount;
        cout << "Deposited Rs. " << amount << " into Savings Account\n";
    }

    void withdraw(float amount)
    {
        if (Balance - amount >= 2000)
        {
            Balance -= amount;
            cout << "Withdrawn Rs. " << amount << " from Savings Account\n";
        }
        else
        {
            cout << "Insufficient balance for withdrawal in Savings Account\n";
        }
    }

    void checkBalanceAndCharge()
    {
        if (Balance < 2000)
        {
            Balance -= 500;
            cout << "Service charge of Rs. 500 imposed due to low balance in Savings Account\n";
        }
    }

    void calculateInterest()
    {
        float interest = 0.10 * Balance;
        Balance += interest;
        cout << "Interest Rs. " << interest << " added to Savings Account\n";
    }

    void displayInfo() override
    {
        cout << "\nAccount Type: Saving Account\n";
        cout << "Account Holder: " << Acc_Holder_Name << "\n";
        cout << "Contact No: " << Acc_Holder_Contact_No << "\n";
        cout << "Account Number: " << S_Acc_No << "\n";
        cout << "Balance: Rs. " << Balance << "\n";
    }

    int getAccNo()
    {
        return S_Acc_No;
    }
};

class Current_Account : public Account
{
private:
    int C_Acc_No;
    float Balance;

public:
    Current_Account(string name, int contact, int accNo, float initialBalance)
        : Account(name, contact)
    {
        C_Acc_No = accNo;
        Balance = initialBalance;
    }

    void deposit(float amount)
    {
        Balance += amount;
        cout << "Deposited Rs. " << amount << " into Current Account\n";
    }

    void withdraw(float amount)
    {
        if (Balance - amount >= 5000)
        {
            Balance -= amount;
            cout << "Withdrawn Rs. " << amount << " from Current Account\n";
            checkBalanceAndCharge();
        }
        else if (Balance < 0)
        {
            cout << "Insufficient balance for withdrawal in Current Account\n";
            checkBalanceAndCharge();
        }
    }

    void checkBalanceAndCharge()
    {
        if (Balance < 5000)
        {
            Balance -= 1000;
            cout << "Service charge of Rs. 1000 imposed due to low balance in Current Account\n";
        }
    }

    void calculateInterest()
    {
        cout << "No interest applicable for Current Account.\n";
    }

    void displayInfo() 
    {
        cout << "\nAccount Type: Current Account\n";
        cout << "Account Holder: " << Acc_Holder_Name << "\n";
        cout << "Contact No: " << Acc_Holder_Contact_No << "\n";
        cout << "Account Number: " << C_Acc_No << "\n";
        cout << "Balance: Rs. " << Balance << "\n";
    }

    int getAccNo()
    {
        return C_Acc_No;
    }
};

int main()
{
    int num;
    int choice, accNo, contact, accountChoice;
    string name;
    float amount, balance;

    cout << "Enter number of accounts to create: ";
    cin >> num;

    Account *acc[num];

    // Input
    for (int i = 0; i < num; ++i)
    {
        cout << "\nEnter details for Account " << i + 1 << ":\n";
        cout << "Enter Account Holder's Name: ";
        cin >> name;
        cout << "Enter Account Holder's Contact Number: ";
        cin >> contact;

        cout << "\nChoose Account Type:\n1. Saving Account\n2. Current Account\nEnter choice: ";
        cin >> accountChoice;

        if (accountChoice == 1)
        {
            cout << "Enter Saving Account Number: ";
            cin >> accNo;
            cout << "Enter Initial Balance: Rs. ";
            cin >> balance;
            acc[i] = new Saving_Account(name, contact, accNo, balance);
        }
        else if (accountChoice == 2)
        {
            cout << "Enter Current Account Number: ";
            cin >> accNo;
            cout << "Enter Initial Balance: Rs. ";
            cin >> balance;
            acc[i] = new Current_Account(name, contact, accNo, balance);
        }
        else
        {
            cout << "Invalid choice!\n";
            return 1;
        }
    }

    // Menu
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Deposit Amount\n";
        cout << "2. Withdraw Amount\n";
        cout << "3. Calculate Interest (Only for Saving Account)\n";
        cout << "4. Display Account Information\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Account Number to deposit: ";
            cin >> accNo;
            bool found = false;
            for (int i = 0; i < num; ++i)
            {
                if (acc[i]->getAccNo() == accNo)
                {
                    found = true;
                    cout << "Enter amount to deposit for Account " << accNo << ": Rs. ";
                    cin >> amount;
                    acc[i]->deposit(amount);
                    break;
                }
            }
            if (!found)
            {
                cout << "Account number not found.\n";
            }
        }
        break;

        case 2:
        {
            cout << "Enter Account Number to withdraw: ";
            cin >> accNo;
            bool found = false;
            for (int i = 0; i < num; ++i)
            {
                if (acc[i]->getAccNo() == accNo)
                {
                    found = true;
                    cout << "Enter amount to withdraw for Account " << accNo << ": Rs. ";
                    cin >> amount;
                    acc[i]->withdraw(amount);
                    break;
                }
            }
            if (!found)
            {
                cout << "Account number not found.\n";
            }
        }
        break;

        case 3:
            for (int i = 0; i < num; ++i)
            {
                acc[i]->calculateInterest();
            }
            break;

        case 4:
            for (int i = 0; i < num; ++i)
            {
                acc[i]->displayInfo();
            }
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

        // Balance Check
        for (int i = 0; i < num; ++i)
        {
            acc[i]->checkBalanceAndCharge();
        }

    } while (choice != 5);

    for (int i = 0; i < num; ++i)
    {
        delete acc[i];
    }

    return 0;
}
