#include <stdio.h>

int nop, nor;
int A[10][10], N[10][10], AV[10], finish[10];

void accept_matrix(int x[10][10])
{
	int i, j;

	for (i = 0; i < nop; i++)
	{
		printf("P%d:\n", i);
		for (j = 0; j < nor; j++)
		{
			printf("%c: ", 65 + j);
			scanf("%d", &x[i][j]);
		}
	}
}

void calc_available()
{
	int i, j;
	int total[10], allocated_sum[10] = {0};

	printf("\nEnter Total instances of each resource:\n");
	for (i = 0; i < nor; i++)
	{
		printf("%c: ", 65 + i);
		scanf("%d", &total[i]);
	}

	for (j = 0; j < nor; j++)
	{
		for (i = 0; i < nop; i++)
		{
			allocated_sum[j] += A[i][j];
		}
		AV[j] = total[j] - allocated_sum[j];
	}
}

void display_data()
{
	int i, j;

	printf("\nProcess\tAllocation\tNeed\n\t");
	for (j = 0; j < nor; j++)
		printf("%4c", 65 + j);
	printf("\t");
	for (j = 0; j < nor; j++)
		printf("%4c", 65 + j);

	for (i = 0; i < nop; i++)
	{
		printf("\nP%d\t", i);
		for (j = 0; j < nor; j++)
			printf("%4d", A[i][j]);
		printf("\t");
		for (j = 0; j < nor; j++)
			printf("%4d", N[i][j]);
	}

	printf("\nAvailable:");
	for (i = 0; i < nor; i++)
		printf("%4d", AV[i]);
	printf("\n");
}

int check_need(int pno)
{
	for (int i = 0; i < nor; i++)
		if (N[pno][i] > AV[i])
			return 0;
	return 1;
}

void banker()
{
	int p = 0, j = 0, k = 0, flag = 0, safe[10];

	while (flag < 2)
	{
		if (!finish[p])
		{
			if (check_need(p))
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
		printf("\nSystem is in SAFE state.\nSafe Sequence: ");
		for (j = 0; j < k; j++)
			printf("P%d ", safe[j]);
	}
	else
	{
		printf("\nSystem is NOT in a safe state, Deadlock possible!\n");
	}
}

int main()
{
	printf("\nEnter No. of Processes: ");
	scanf("%d", &nop);

	printf("Enter No. of Resource types: ");
	scanf("%d", &nor);

	printf("Enter Available Matrix:");
	accept_matrix(A);

	printf("Enter Request Matrix:");
	accept_matrix(N);

	calc_available();
	display_data();

	banker();

	return 0;
}
