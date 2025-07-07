import java.io.*;


class A1SetB1
{

	public static void main(String args[]) throws IOException
	{
		int num;
		
		num = Integer.parseInt(args[0]);

		
		MyNumber n1 = new MyNumber();
		MyNumber n2 = new MyNumber(num);

		System.out.println("\nNumber: " + n1.display());
		System.out.println("IsNegative: " + n1.isNegative());
		System.out.println("IsPositive: " + n1.isPositive());
		System.out.println("IsOdd: " + n1.isOdd());
		System.out.println("IsEven: " + n1.isEven());
		
		System.out.println("\nNumber: " + n2.display());
		System.out.println("IsNegative: " + n2.isNegative());
		System.out.println("IsPositive: " + n2.isPositive());
		System.out.println("IsOdd: " + n2.isOdd());
		System.out.println("IsEven: " + n2.isEven());
		
	}
}

class MyNumber
{
	private int num;
	
	public MyNumber()
	{
		this.num = 0;
	}

	public MyNumber(int num)
	{
		this.num = num;

	}
	
	public boolean isNegative()
	{
		if(num < 0)
			return true;
		
		return false;
	}
	
	public boolean isPositive()
	{
		if(num > 0)
			return true;
		
		return false;
	}
	
	public boolean isOdd()
	{
		if(num % 2 != 0)
			return true;
		
		return false;
	}
	
	public boolean isEven()
	{
		if(num % 2 == 0)
			return true;
		
		return false;
	}
	
	public int display()
	{
		return this.num;
	}
}


