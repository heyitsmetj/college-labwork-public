import java.io.*;
import java.util.Scanner;

class Factorial
{
	public static void main(String args[]) throws IOException
	{
		
		int num, fact = 1;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter your Number: ");
		num = sc.nextInt();

		for(int i = num; i > 0; i--)
			fact *= i;
			
		System.out.println("Factorial of " + num + " is " + fact);
		
		sc.close();

	}
}
