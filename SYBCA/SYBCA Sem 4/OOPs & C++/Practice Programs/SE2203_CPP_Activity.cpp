/*
	Bank Application
	Roll_no:- SE2203
*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Account
{
	int acc_id;
	string user_name;
	string acc_type;
	int dob[3];
	string addr;
	float balance;
	
	public:
	
		Account()
		{
			acc_id = 00;
			user_name = "New_Customer";
			acc_type = "Savings";
			dob[0] = 01;
			dob[1] = 01;
			dob[2] = 2000;
			addr = "Default Address";
			balance = 0;
		}
		
		void accept()
		{
			char ch;
			
			cout << "\nEnter acc_id: ";
			cin >> acc_id;
			cout << "Enter your name: ";
			cin >> user_name;
			cout << "Choose your Account Type(S: Savings, C: Current): ";
			cin >> ch;
			if(ch == 's' || ch == 'S')
			{
				acc_type = "Savings";
			}
			else if(ch == 'C' || ch == 'c')
			{
				acc_type = "Current";
			}
			else
			{
				cout << "Error! Default values set to Savings.";
				acc_type = "Savings";	
			}
			
			cout << "Enter Day part of DOB(00): ";
			cin >> dob[0];
			cout << "Enter Month part of DOB(00): ";
			cin >> dob[1];
			cout << "Enter Year part of DOB(0000): ";
			cin >> dob[2];
			
			cout << "Enter Address: ";
			cin >> addr;
			
			balance = 0;
		}
		
		void display()
		{
			cout << fixed << setprecision(2) << left << setw(20) << "\nAcc_id: " << acc_id << endl;
			cout << fixed << setprecision(2) << left << setw(20) << "User_name: " << user_name << endl;
			cout << fixed << setprecision(2) << left << setw(20) << "Acc_type: " << acc_type << endl;
			cout << fixed << setprecision(2) << left << setw(20) << "DOB: " << dob[0] << "-" << dob[1] << "-" << dob[2] << endl;
			cout << fixed << setprecision(2) << left << setw(20) << "Address: " << addr << endl;
			cout << fixed << setprecision(2) << left << setw(20) << "Balance: " << balance << endl;
		}

};

int main()
{
	
	Account accs[100];
	int size;
	
	cout << "\nHow many accounts do you want to enter?:";
	cin >> size;
	
	for(int i = 0; i < size; i++)
	{
		char ch;
		cout << "\nDo you want to enter the account details of account " << i+1 << "?(Y/N): ";
		cin >> ch;
		if(ch == 'Y' || ch == 'y')
		{
			cout << "\nEnter Accout " << i+1 << " details:" << endl; 
			accs[i].accept();
			cout << "\nAccount details set!\n" << endl;
		}
		else{
			cout << "\nDefault values set!\n" << endl;
		}
	}
	
	
	for(int i = 0; i < size; i++)
	{
			cout << "\nAccout " << i+1 << " details:" << endl; 
			accs[i].display();
	}

    return 0;
}
