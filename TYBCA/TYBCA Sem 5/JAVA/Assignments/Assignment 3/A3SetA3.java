import java.util.*;
import java.io.*;

class A3SetA3
{
	public static void main(String args[])
	{
		int num;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter Num: ");
		num = sc.nextInt();
		
		try
		{
			if(num == 0)
			{
				throw new ZeroNumException("\nNumber is Zero");
			}
			else
			{
				boolean isPrime = true;
				 
				for(int i=2; i<num; i++)
				{
					if(num%i == 0)
					{
						isPrime = false;			
						break;
					}
				}
				
				if(isPrime)
				{
					System.out.println(num + " is a Prime Number.");
				}
				else
				{
					System.out.println(num + " is NOT a Prime Number.");
				}
				
			}
		}
		catch(ZeroNumException e)
		{
			System.out.println(e.getMessage());
		}
	}
}

class ZeroNumException extends Exception
{
	public ZeroNumException(String msg)
	{
		super(msg);
	}
}
