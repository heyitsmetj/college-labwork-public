#include<stdio.h>
#include<stdlib.h>

int i, nop, nor, A[10][10], M[10][10], AV[10], N[10][10], finish[10];

void acceptdata(int x[10][10])
{
	int i, j;
	
	for(i = 0; i< nop; i++)
	{
		printf("\nP%d\n",i);
		
		for(j = 0; j < nor; j++)
		{
			printf("%c: ", 65+j);
			scanf("%d", &x[i][j]);
		}
	}
}

void acceptav()
{
	int i;
	for(i=0; i<nor; i++)
	{
		printf("%c: ", 65+i);
		scanf("%d", &AV[i]);
	}
}

void calcneed()
{
	int i, j;
	
	for(i = 0; i<nop; i++)
	{
		for(j = 0; j < nor; j++)
		{
			N[i][j] = M[i][j] - A[i][j];
		}
	}
}

void displaydata()
{
	int i, j;
	
	printf("\n\t\tAllocation\t\tMAX\n\t");
	for(i = 0; i < 2; i++)
	{
		for(j=0;j<nor;j++)
		{
			printf("%4c", 65+j);
		}
		
		printf("\t");
	}
	
	for(i=0; i<nop; i++)
	{
		printf("\nP%d\t", i);
		for(j=0; j<nor; j++)
			printf("%4d", A[i][j]);
		printf("\t");
		for(j=0; j<nor; j++)
			printf("%4d", M[i][j]);
	}
}

void displayavail()
{
	printf("\nAvailable: ");
	for(i=0;i<nor;i++)
		printf("%4d", AV[i]);
		
	printf("\n");
}

void displayneed()
{
	int i, j;
	
	printf("\nNeed Matrix: \n\t");
	for(j=0;j<nor;j++)
	{
		printf("%4c", 65+j);
		printf("\t");
	}
	
	for(i=0; i<nop; i++)
	{
		printf("\nP%d\t", i);
		for(j=0; j<nor; j++)
			printf("%d\t", N[i][j]);
	}
}

int main()
{
	int ch;
	
	printf("\nEnter No. of Processes: ");
	scanf("%d", &nop);
	
	printf("\nEnter No. of Resources: ");
	scanf("%d", &nor);
	
	printf("\nEnter Allocation Matrix: ");
	acceptdata(A);
	
	printf("\nEnter Max Matrix: ");
	acceptdata(M);
	
	while(1)
	{
		printf("\n1.Accept Available.\n2.Display Allocation, Max.\n3.Find Need and Display It.\n4.Display Available.\n5.Exit.");
		printf("\nEnter choice:");
		scanf("%d", &ch);
		switch(ch)
		{	
			case 1:
				printf("\nEnter Availability: ");
				acceptav();
				break;
			
			case 2:
				calcneed();
				displaydata();
				break;
				
			case 3:
				calcneed();
				displayneed();
				break;
			
			case 4:
				displayavail();
				break;
				
			case 5:
				exit(0);
		}
	}
	return 0;
}

