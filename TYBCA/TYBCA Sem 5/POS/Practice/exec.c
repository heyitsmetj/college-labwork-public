#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("I am in exec.c file.");
    printf("\nPID of exec.c : %d.", getpid());

    char *args[] = {"./hello.c", NULL};
    execv(args[0], args);

    printf("\nComing back to exec.c.");
    return 1;
}

