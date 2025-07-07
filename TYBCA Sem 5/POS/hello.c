#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("I am in hello.c file.");
    printf("\nPID of hello.c : %d.", getpid());
    return 1;
}

