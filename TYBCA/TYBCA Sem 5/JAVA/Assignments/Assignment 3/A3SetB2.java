import java.io.*;
import java.util.Scanner;

class InvalidNameException extends Exception
{
	public InvalidNameException(String message)
	{
		super(message);
	}
}

class A3SetB2
{
	public static void checkDoctorName(String name) throws InvalidNameException
	{
		if(!name.matches("[a-zA-Z]+"))
		{
			throw new InvalidNameException("Exception Raised: Name is Invalid. It should not contain digits or special symbols.");
		}
		else
		{
			System.out.println("Doctor Name is Valid: " + name);
		}
	}
		
	public static void main(String args[])
	{	
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter Doctor's Name: ");
		String doctorName = sc.nextLine();
	
		try
		{
			checkDoctorName(doctorName);
		}
		catch(InvalidNameException e)
		{
			System.out.println(e.getMessage());
		}
		
		sc.close();
	}
}
