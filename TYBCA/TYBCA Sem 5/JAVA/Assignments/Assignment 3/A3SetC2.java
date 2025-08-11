import java.io.*;
import java.util.*;

class MyDate
{
	int date, month, year;
	
	public MyDate(int d, int m, int y)
	{
		this.date = d;
		this.month = m;
		this.year = y;
	}
	
	public void display()
	{
		System.out.println("Entered Date: " + this.date + "-" + this.month + "-" + this.year);
	}
	
	public int getDate()
	{
		return this.date;
	}
	
	public int getMonth()
	{
		return this.month;
	}
	
	public int getYear()
	{
		return this.year;
	}
}

class InvalidDateException extends Exception
{
	public InvalidDateException(String message)
	{
		super(message);
	}
}

class A3SetC2
{
	public static void checkDate(MyDate date) throws InvalidDateException
	{
		boolean invalid = false;
		
		boolean isLeapYear = false;
		
		int year = date.getYear();
		
		if(year % 4 == 0)
		{
			if(year % 100 == 0)
			{
				if(year % 400 == 0)
				{
					isLeapYear = true;
				}
				else
				{
					isLeapYear = false;
				}
			}
			else
			{
				isLeapYear = true;
			}
		}
		else
		{
			isLeapYear = false;
		}
		
		if(date.getDate() > 31 || date.getMonth() > 12)
			invalid = true;
		
		if(date.getDate() > 28 && date.getMonth() == 2 && isLeapYear == false)
			invalid = true;
			
		if(date.getMonth() % 2 == 0 && date.getDate() > 30 && date.getMonth() != 2)
			invalid = true;
			
		if(invalid)
		{
			throw new InvalidDateException("Exception Raised: Invalid Date Format!");
		}
		else
		{
			date.display();
		}		
	}
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter Date(dd): ");
		int d = sc.nextInt();
		System.out.print("Enter Month(mm): ");
		int m = sc.nextInt();
		System.out.print("Enter Year(yyyy): ");
		int y = sc.nextInt();
		
		MyDate date = new MyDate(d, m, y);
		
		try
		{
			checkDate(date);
		}
		catch(InvalidDateException e)
		{
			System.out.println(e.getMessage());
		}
	}
}
