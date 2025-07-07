import java.io.*;
import java.util.Scanner;

class ScanInput
{
	public static void main(String args[]) throws IOException
	{
		
		int rno;
		String name;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter your Roll No.: ");
		rno = sc.nextInt();
		System.out.print("Enter your Name: ");
		name = sc.next();
		
		System.out.println("\nRoll No.: " + rno + "\nName: " + name);
		
		sc.close();

	}
}
