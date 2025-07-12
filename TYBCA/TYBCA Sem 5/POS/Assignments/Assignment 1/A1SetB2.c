#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int pid, retnice; 
	

	printf("press DEL to stop process\n");
	pid = fork();
	
	for(int i = 0;i < 5;i++)
	{
		if(pid == 0)
		{
			retnice = nice(-5);
			printf("\nChild gets higher CPU priority: %d\n", retnice);
			sleep(1);
		}
		else
		{
			retnice = nice(4);
			printf("Parent gets lower CPU priority: %d\n", retnice);
			sleep(1);	
		}
	}
	
}
