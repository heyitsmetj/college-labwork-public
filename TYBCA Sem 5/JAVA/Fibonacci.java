import java.io.*;
import java.util.Scanner;

class Fibonacci
{
	public static void main(String args[]) throws IOException
	{
		
		int limit, a = 0, b = 1, c;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the limit for Fibonacci Series: ");
		limit = sc.nextInt();
		
		System.out.print("Your Series: " + a + " " + b);
		
		for(int i = 0; i < limit - 2; i++)
		{
			c = a + b;
			a = b;
			b = c;
			
			System.out.print(" " + c);
		}
		
		sc.close();

	}
}
