import java.io.*;

class A1SetA3
{
	public static void BSort(int[] arr, int size)
	{
		int i, j, temp;
		
		for(i = 0; i < size; i++)
		{
			for(j = 0; j < size - i - 1; j++)
			{
				if(arr[j] > arr[j+1])
				{
					temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

	public static void main(String args[]) throws IOException
	{
		
		int size, sum = 0;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Enter size of array: ");
		size = Integer.parseInt(br.readLine());
		
		int[] arr = new int[size];
		
		for(int i = 0;i < size; i++)
		{
			System.out.print("Enter element[" + (i) + "]: ");
			arr[i] = Integer.parseInt(br.readLine());
			
			sum += arr[i];
		}
		
		System.out.print("\nYour Array: ");
		for (int i = 0; i < size; i++)
		{
            System.out.print(arr[i] + " ");
		}
		
		BSort(arr, size);
		
		System.out.println("\nSum of array elements: " + sum);
		
		System.out.print("Your Array in Ascending Order: ");
		for (int i = 0; i < size; i++)
		{
            System.out.print(arr[i] + " ");
		}
	}
}
