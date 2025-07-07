import java.io.*;

class A1SetA1
{
	public static void main(String args[]) throws IOException
	{
		
		int num;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Enter number for multiplication table: ");
		num = Integer.parseInt(br.readLine());
		
		for(int i = 1; i <= 10; i++)
		{
			System.out.println(num + " x " + i + " = " + (num*i));
		}
	
	}
}
