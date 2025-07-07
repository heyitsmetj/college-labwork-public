import java.io.*;

class A1SetA2
{
	public static void main(String args[]) throws IOException
	{
		
		int num,rem = 0,rev = 0;
		
		num = Integer.parseInt(args[0]);
		
		int temp = num;
		
		while(temp != 0)
		{
			rem = temp % 10;
			rev = (rev * 10) + rem;
			temp = temp / 10;
		}
		
			System.out.println("Number: " + num + "\nReversed Number: " + rev);
	
	}
}
