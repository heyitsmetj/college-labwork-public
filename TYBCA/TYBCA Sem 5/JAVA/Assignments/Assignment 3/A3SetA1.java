import java.util.*;
import java.io.*;

class A3SetA1
{
	public static void main(String args[])
	{
		TreeSet <Integer> numbers = new TreeSet<>();
		int n;
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\nEnter the number of elements: ");
		n = sc.nextInt();
		
		for(int i = 0; i<n; i++)
		{
			System.out.print("Enter number[" + i + "]: ");
			numbers.add(sc.nextInt());
			
		}
		
		System.out.println("\nYour Numbers: " + numbers);
		
		System.out.print("\nYour Search Key: ");
		int key = sc.nextInt();
		
		if(numbers.contains(key))
		{
			System.out.println(key + " is present in the Collection.");
		}
		else
		{
			System.out.println(key + " is NOT present in the collection.");
		}
	}
}
