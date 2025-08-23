#include<stdio.h>

int nop, nor, A[10][10], M[10][10], AV[10], N[10][10], finish[10];

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
	
	printf("\n\tAllocation\t\tMAX\t\tNeed\n\t");
	for(i = 0; i < 3; i++)
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
		printf("\t");
		for(j=0; j<nor; j++)
			printf("%4d", N[i][j]);
	}
	printf("\n\nAvailable: ");
	for(i=0;i<nor;i++)
		printf("%4d", AV[i]);
}

int checkneed(int pno)
{
	int i;
	for(i = 0; i<nor; i++)
		if(N[pno][i]>AV[i])
			return 0;
	return 1;
}

int main()
{
	printf("\nEnter No. of Processes: ");
	scanf("%d", &nop);
	
	printf("\nEnter No. of Resources: ");
	scanf("%d", &nor);
	
	printf("\nEnter Allocation Matrix: ");
	acceptdata(A);
	
	printf("\nEnter Max Matrix: ");
	acceptdata(M);
	
	printf("\nEnter Availability: \n");
	acceptav();
	calcneed();
	displaydata();

	return 0;
}

