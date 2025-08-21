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
	
		if (year % 4 == 0) 
		{
		    if (year % 100 == 0) 
		    {
		        if (year % 400 == 0) 
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
		
		int d = date.getDate();
		int m = date.getMonth();
		
		if (m < 1 || m > 12) 
		{
		    invalid = true;
		} 
		else 
		{
		    switch(m) 
		    {
		        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		            if (d < 1 || d > 31) 
		            	invalid = true;
		            break;
		            
		        case 4: case 6: case 9: case 11:
		            if (d < 1 || d > 30) 
		            	invalid = true;
		            break;
		        
		        case 2:
		            if (isLeapYear) 
		            {
		                if (d < 1 || d > 29) 
		                	invalid = true;
		            } 
		            else 
		            {
		                if (d < 1 || d > 28) 
		                	invalid = true;
		            }
		            break;
		    }
		}
		
		if (invalid) 
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
