import java.io.*;

class CLIInput
{
	public static void main(String args[])
	{
		
		int a, b;
		
		a = Integer.parseInt(args[0]);
		b = Integer.parseInt(args[1]);
		
		int sum = a + b;
		int sub = a - b;
		int div = a / b;
		int mul = a * b;
		
		System.out.println(a + " + " + b + " = " + sum);
		System.out.println(a + " - " + b + " = " + sub);
		System.out.println(a + " * " + b + " = " + mul);
		System.out.println(a + " / " + b + " = " + div);
	
	}
}
