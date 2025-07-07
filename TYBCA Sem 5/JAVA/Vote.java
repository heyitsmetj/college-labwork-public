import java.io.*;
import java.util.Scanner;

class Vote
{
	public static void main(String args[]) throws IOException
	{
		
		int age;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter your Age: ");
		age = sc.nextInt();

		if(age >= 18)
			System.out.println("You are Eligible!");
		else
			System.out.println("You are NOT Eligible!");
		
		sc.close();

	}
}
