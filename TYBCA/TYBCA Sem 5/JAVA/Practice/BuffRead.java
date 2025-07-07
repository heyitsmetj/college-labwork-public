import java.io.*;

class BuffRead
{
	public static void main(String args[]) throws IOException
	{
		
		int rno;
		String name;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Enter your Roll No.: ");
		rno = Integer.parseInt(br.readLine());
		System.out.print("Enter your Name: ");
		name = br.readLine();
		
		
		System.out.println("\nRoll No.: " + rno + "\nName: " + name);

	}
}
