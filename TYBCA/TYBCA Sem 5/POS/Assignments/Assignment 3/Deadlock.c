#include <stdio.h>

int nop, nor;
int A[10][10], M[10][10], AV[10], N[10][10], finish[10];

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

void calcav() {
    int i, j;
    int TR[10];
    int TA[10] = {0};

    printf("\nEnter total instances of each resource:\n");
    for (i = 0; i < nor; i++) 
    {
        printf("%c: ", 65 + i);
        scanf("%d", &TR[i]);
    }

    for (j = 0; j < nor; j++) 
    {
        for (i = 0; i < nop; i++) 
        {
            TA[j] += A[i][j];
        }
    }

    for (i = 0; i < nor; i++) 
    {
        AV[i] = TR[i] - TA[i];
    }
}

void calcneed() {
    int i, j;
    for (i = 0; i < nop; i++) {
        for (j = 0; j < nor; j++) {
            N[i][j] = M[i][j] - A[i][j];
        }
    }
}

void displaydata() {
    int i, j;

    printf("\n\tAllocation\t\tMAX\t\tNeed\n\t");
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < nor; j++) 
        {
            printf("%4c", 65 + j);
        }
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

    printf("\nAvailable:");
    for (i = 0; i < nor; i++)
        printf("%4d", AV[i]);
    printf("\n");
}

int checkneed(int pno) {
    for (int i = 0; i < nor; i++) 
    {
        if (N[pno][i] > AV[i])
            return 0;
    }
    return 1;
}

void banker() 
{
    int safe[10], count = 0, progress;

    for (int i = 0; i < nop; i++)
        finish[i] = 0;

    while (count < nop) 
    {
        progress = 0;
        for (int p = 0; p < nop; p++) 
        {
            if (!finish[p] && checkneed(p)) 
            {
                printf("\nProcess P%d can be safely executed.", p);
                for (int j = 0; j < nor; j++)
                    AV[j] += A[p][j];
                
                finish[p] = 1;
                safe[count++] = p;
                progress = 1;
            }
        }
        if (!progress)
            break;
    }

    if (count == nop) 
    {
        printf("\n\nSystem is in a SAFE state.");
        printf("\nSafe sequence: ");
        for (int i = 0; i < nop; i++)
            printf("P%d%s", safe[i], (i == nop - 1) ? "" : " -> ");
    } 
    else 
    {
        printf("\n\nSystem is in an UNSAFE state — DEADLOCK detected.");
        
        printf("\nDeadlocked processes: ");
        for (int i = 0; i < nop; i++) {
            if (!finish[i])
                printf("P%d ", i);
        }
    }
}

int main() {
    printf("\nEnter number of processes: ");
    scanf("%d", &nop);

    printf("\nEnter number of resources: ");
    scanf("%d", &nor);

    printf("\nEnter Allocation Matrix:\n");
    acceptdata(A);

    printf("\nEnter Max Matrix:\n");
    acceptdata(M);

    calcav();
    calcneed();

    displaydata();
    banker();

    return 0;
}

