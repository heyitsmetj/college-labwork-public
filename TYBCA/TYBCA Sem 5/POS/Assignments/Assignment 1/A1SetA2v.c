#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pid = fork();

    if (pid < 0) 
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        char *args[] = {"./hello", NULL};
        execv(args[0], args);

        perror("execv failed");
        
    } 
    else 
    {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}

