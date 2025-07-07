import java.io.*;
import java.util.Scanner;

class A1SetA4
{

	public static void main(String args[]) throws IOException
	{
		int date, month, year;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter Date(dd): ");
		date = sc.nextInt();
		
		System.out.print("Enter Month(mm): ");
		month = sc.nextInt();
		
		System.out.print("Enter Year(yyyy): ");
		year = sc.nextInt();
		
		MyDate obj1 = new MyDate();
		MyDate obj2 = new MyDate(date, month, year);
		
		obj1.display();
		obj2.display();
		
		
	}
}

class MyDate
{
	int dd,mm,yyyy;
	
	public MyDate()
	{
		this.dd = 01;
		this.mm = 01;
		this.yyyy = 2000;
	}

	public MyDate(int date, int month, int year)
	{
		this.dd = date;
		this.mm = month;
		this.yyyy = year;
	}
	
	public void display()
	{
		System.out.println("Entered Date: " + dd + "-" + mm + "-"+ yyyy);
	}
}


