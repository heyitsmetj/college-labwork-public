#include<stdio.h>

void main()
{
	int start,end,mid,key,i,flag=0;
	int n = 10;
	
	int array[10]={1,5,7,12,13,16,17,22,24,26};

	printf(" Your array: ");
	
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}
	
	int temp,j;
	
	 for (int i = 0; i < n - 1; ++i)
	 {
	 	for (int j = 0; j < n - i - 1; ++j) 
	 	{
      
      	if (array[j] > array[j + 1]) 
      	{
       
        	int temp = array[j];
        	array[j] = array[j + 1];
        	array[j + 1] = temp;
      	}
    }
  }
	
	printf("\n Your sorted array: ");
	
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}
	
	printf("\n Enter the element to search: ");
	scanf("%d",&key);
	
	
	start = 0;
	end = n-1;

	
	while( start <= end )
	{
		mid = (start + end) / 2;
		
		if(array[mid] == key)
		{
			flag=1;
			break;
		}
		
		else if(array[mid] < key)
		{
			start = mid + 1;
		}
		
		else if(array[mid] > key)
		{
			end = mid - 1;
		}
	}
	
	if(flag != 0)
	{
		printf("\n %d is at %d position\n",key,mid+1);
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	else
	{
		printf("\n %d not found in Array\n",key);
	}
}











