#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <stdlib.h>

int main()
{
	int pid;
	pid = fork();
	if(pid < 0)
	{
		perror("\nFork failed!");
	}
	else if(pid == 0)
	{
		printf("\nChild PID: %d", getpid());
		printf("\nHello, World!");
	}
	else
	{
		printf("\nParent PID: %d, Child PID: %d", getpid(), pid);
		printf("\nHi!\n");
	}
	
	return 0;
}
