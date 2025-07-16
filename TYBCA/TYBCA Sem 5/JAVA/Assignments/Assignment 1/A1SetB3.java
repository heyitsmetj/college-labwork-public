import java.io.*;
import java.util.Scanner;

class Account {
	int accno;
	String accname;
	float balance;

	public Account() 
	{
		this.accno = 0;
		this.accname = "NewAccount";
		this.balance = 0;
	}

	public Account(int accn, String n, float bal) 
	{
		this.accno = accn;
		this.accname = n;
		this.balance = bal;
	}


	public void display() 
	{
		System.out.println("\nAccount No.: " + accno);
		System.out.println("Account Name: " + accname);
		System.out.println("Account Balance: " + balance);
	}
	
	public static void sortAccount(Account accs[])
	{
		int i, j;
		Account temp;
		
		for(i = 0; i < accs.length; i++)
		{
			for(j = 0; j < accs.length - i - 1; j++)
			{
				if(accs[j].balance > accs[j+1].balance)
				{
					temp = accs[j+1];
					accs[j+1] = accs[j];
					accs[j] = temp;
				}
			}
		}
	}
}

	class A1SetB3 {

	public static void main(String args[]) throws IOException {

		int size, accn;
		String n;
		float bal;

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter number of objects: ");
		size = sc.nextInt();

		Account[] accs = new Account[size];

		for (int i = 0; i < size; i++) 
		{
			System.out.print("\nEnter [" + (i+1) + "]Account No.: ");
			accn = sc.nextInt();
			sc.nextLine();
			System.out.print("Enter  [" + (i+1) + "] Account Name: ");
			n = sc.nextLine();
			System.out.print("Enter [" + (i+1) + "]Account Balance: ");
			bal = sc.nextFloat();

			accs[i] = new Account(accn, n, bal); 
		}
		
		Account.sortAccount(accs);

		System.out.println("\nEmployee Details:");

		for (int i = 0; i < size; i++) 
		{
			accs[i].display();
		}

	}
}


