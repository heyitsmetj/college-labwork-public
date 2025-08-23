#include <stdio.h>

int main() {
    int n, maxNeed, minResources;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter maximum resources needed by a single process: ");
    scanf("%d", &maxNeed);

    minResources = n * (maxNeed - 1) + 1;

    printf("\nMinimum number of resources needed to avoid deadlock: %d\n", minResources);

    return 0;
}
