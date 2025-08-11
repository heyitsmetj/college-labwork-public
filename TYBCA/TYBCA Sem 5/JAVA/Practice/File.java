import java.io.*;
import java.util.*;

class File
{
	public static void main(String args[]) throws IOException
	{
		
		
		FileReader ("test.txt");
		
		while(fp != -1)
		{
			System.out.println(fp.read());
		}
		
		fp.close();

	}
}
