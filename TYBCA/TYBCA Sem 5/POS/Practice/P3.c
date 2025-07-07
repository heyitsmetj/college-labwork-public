#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int pid;
	pid = fork();
	
	if(pid < 0)
	{
		fprintf(stderr, "Fork Failed!");
		return 1;
	}
	
	else if(pid == 0)
	{
		execlp("/bin/ls", "ls", NULL);
	}
	
	else
	{
		wait(NULL);
		printf("Child Complete!");
	}
	
	return 0;
}
