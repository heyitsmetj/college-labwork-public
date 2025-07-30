#include <stdio.h>
int nor, nof, refstring[30], F[10];

void accept()
{
    int i;
    printf("\nEnter the Reference String:\n");
    for (i = 0; i < nor; i++)
    {
        printf("[%d]: ", i);
        scanf("%d", &refstring[i]);
    }
}

int search(int page)
{
    int i;
    for (i = 0; i < nof; i++)
    {
        if (page == F[i])
            return i;
    }
    return -1;
}

int getfno(int i)
{
    int prev, fno, fpos = 0;
    
    for (prev = i - 1; prev >= 0; prev--)
    {
        for (fno = 0; fno < nof; fno++)
        {
            if (F[fno] == refstring[prev])
            {
                fpos = fno;
                return fpos;
            }
        }
    }
    return fpos;
}


void MRU()
{
    int i, j, k, fno = 0, fault = 0;

    printf("\n--- MRU Page Replacement ---\n");
    
    for (j = 0; j < nof; j++)
        F[j] = -1;

    for (i = 0; i < nor; i++)
    {
        printf("\n%d: ", refstring[i]);
        k = search(refstring[i]);

        if (k == -1)
        { 
            if (fno < nof)
                F[fno++] = refstring[i];
            else
                F[getfno(i)] = refstring[i];

            for (j = 0; j < nof; j++)
            {
                if (F[j] != -1)
                    printf("\t%d", F[j]);
                else
                    printf("\t-");
                    
            }
            fault++;
        }
        else
        {
            printf("No Page Fault.");
        }
    }

    printf("\n\nTotal number of Page Faults: %d", fault);
}

int main()
{
    printf("\nEnter the Length of the String: ");
    scanf("%d", &nor);

    printf("\nEnter number of Frames: ");
    scanf("%d", &nof);

    accept();
    MRU();

    return 0;
}
