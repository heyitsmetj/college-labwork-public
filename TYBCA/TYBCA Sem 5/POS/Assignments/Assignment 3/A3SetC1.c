#include <stdio.h>

int nop, nor, A[10][10], M[10][10], AV[10], N[10][10], finish[10];

void acceptdata(int x[10][10])
{
	int i, j;
	for (i = 0; i < nop; i++)
	{
		printf("\nP%d\n", i);
		for (j = 0; j < nor; j++)
		{
			printf("%c: ", 65 + j);
			scanf("%d", &x[i][j]);
		}
	}
}

void acceptav()
{
	int i;
	for (i = 0; i < nor; i++)
	{
		printf("%c: ", 65 + i);
		scanf("%d", &AV[i]);
	}
}

void calcneed()
{
	int i, j;
	for (i = 0; i < nop; i++)
		for (j = 0; j < nor; j++)
			N[i][j] = M[i][j] - A[i][j];
}

void displaydata()
{
	int i, j;
	printf("\n\tAllocation\t\tMAX\t\tNeed\n\t");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < nor; j++)
			printf("%4c", 65 + j);
		printf("\t");
	}

	for (i = 0; i < nop; i++)
	{
		printf("\nP%d\t", i);
		for (j = 0; j < nor; j++)
			printf("%4d", A[i][j]);
		printf("\t");
		
		for (j = 0; j < nor; j++)
			printf("%4d", M[i][j]);
		printf("\t");
		
		for (j = 0; j < nor; j++)
			printf("%4d", N[i][j]);
	}
	
	printf("\n\nAvailable:");
	for (i = 0; i < nor; i++)
		printf("%4d", AV[i]);
	printf("\n\n");
}

int checkneed(int pno)
{
	int i;
	for (i = 0; i < nor; i++)
		if (N[pno][i] > AV[i])
			return 0;
	return 1;
}

void banker()
{
	int p = 0, j = 0, k = 0, flag = 0, safe[10];
	for (int i = 0; i < nop; i++)
		finish[i] = 0;

	while (flag < 2)
	{
		if (!finish[p])
		{
			if (checkneed(p))
			{
				for (j = 0; j < nor; j++)
					AV[j] += A[p][j];
				finish[p] = 1;
				safe[k++] = p;
			}
		}
		if ((p + 1) % nop == 0)
			flag++;
		p = (p + 1) % nop;
	}

	if (k == nop)
	{
		printf("\nSystem is in Safe state...");
		printf("\nSafe Sequence: ");
		for (j = 0; j < k; j++)
			printf("P%d ", safe[j]);
		printf("\n");
	}
	else
	{
		printf("\nSystem is NOT in Safe state...\n");
	}
}

void resource_request()
{
	int pno, req[10], i;
	printf("\nEnter process number making request: ");
	scanf("%d", &pno);

	printf("\nEnter request for each resource:\n");
	for (i = 0; i < nor; i++)
	{
		printf("%c: ", 65 + i);
		scanf("%d", &req[i]);
	}

	for (i = 0; i < nor; i++)
	{
		if (req[i] > N[pno][i])
		{
			printf("\nError: Process has exceeded its maximum claim.\n");
			return;
		}
	}

	for (i = 0; i < nor; i++)
	{
		if (req[i] > AV[i])
		{
			printf("\nProcess must wait: resources not available.\n");
			return;
		}
	}

	int A_copy[10][10], N_copy[10][10], AV_copy[10];
	for (int x = 0; x < nop; x++)
		for (int y = 0; y < nor; y++)
		{
			A_copy[x][y] = A[x][y];
			N_copy[x][y] = N[x][y];
		}
	for (int y = 0; y < nor; y++)
		AV_copy[y] = AV[y];

	for (i = 0; i < nor; i++)
	{
		AV[i] -= req[i];
		A[pno][i] += req[i];
		N[pno][i] -= req[i];
	}

	printf("\nChecking safety after granting request...\n");
	banker();

	int allFinished = 1;
	for (i = 0; i < nop; i++)
		if (!finish[i])
			allFinished = 0;

	if (!allFinished)
	{
		printf("\nRequest would lead to UNSAFE state. Rolling back.\n");
		for (int x = 0; x < nop; x++)
			for (int y = 0; y < nor; y++)
			{
				A[x][y] = A_copy[x][y];
				N[x][y] = N_copy[x][y];
			}
		for (int y = 0; y < nor; y++)
			AV[y] = AV_copy[y];
	}
	else
	{
		printf("\nRequest granted successfully.\n");
	}
}

int main()
{
	int choice;
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

	while (1)
	{
		printf("\n\nMenu:\n1. Check Safe State\n2. Make Resource Request\n3. Exit\nChoice: ");
		scanf("%d", &choice);

		if (choice == 1)
			banker();
		else if (choice == 2)
			resource_request();
		else if (choice == 3)
			break;
		else
			printf("\nInvalid choice!");
	}

	return 0;
}
