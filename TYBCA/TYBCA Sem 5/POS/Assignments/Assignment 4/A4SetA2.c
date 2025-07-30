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

void FIFO()
{
    int i, j, k, fno = 0, fault = 0;

    for (j = 0; j < nof; j++)
        F[j] = -1;

    printf("\n--- FIFO Page Replacement ---\n");

    for (i = 0; i < nor; i++)
    {
        printf("\n%d: ", refstring[i]);
        k = search(refstring[i]);

        if (k == -1)
        {
            F[fno] = refstring[i];
            for (j = 0; j < nof; j++)
            {
                if (F[j] != -1)
                    printf("\t%d", F[j]);
                else
                    printf("\t-");
            }
            fault++;
            fno = (fno + 1) % nof;
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
    FIFO();

    return 0;
}
