#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int pid;
	
	pid = fork();
	
	if(pid < 0){
		printf("Error in creation of Child Process!");
		exit(1);
	}
	else if(pid == 0){
		printf("Hello, I am the Child Process!");
		printf("\nMy PID is %d.", getpid());
		exit(0);
	}
	else{
		printf("Hello, I am the Parent Process!");
		printf("\nMy PID is %d.", getpid());
		exit(1);
	}
	
}
