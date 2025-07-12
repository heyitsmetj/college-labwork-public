#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdlib.h>
#include <string.h>

char *buff, *t1, *t2, *t3;
char ch;
FILE *fp;
int pid;

void count(char *t2, char *t3)
{
	int charcount = 0, wordcount = 0, linecount = 0;
	
	fp = fopen(t3, "r");
	
	if(fp == NULL)
	{
		printf("\nError in opening the file...\n");
	}
	else
	{
		while((ch = fgetc(fp)) != EOF)
		{
			if(ch == ' ')
				wordcount++;
			else if(ch == '\n')
			{
				linecount++;
				wordcount++;
			}
			else
				charcount++;
		}
		
	}
	fclose(fp);
	
	if(strcmp(t2,"c") == 0)
		printf("\nTotal no. of character: %d", charcount);
	else if(strcmp(t2,"w") == 0)
		printf("\nTotal no. of words: %d", wordcount);
	else if(strcmp(t2,"l") == 0)
		printf("\nTotal no. of lines: %d", linecount);
	else
		printf("\nCommand NOT Found!");
}

int main()
{
	while(1)
	{
		printf("\nMyshell$");
		buff = (char*)malloc(80);
		t1 = (char*)malloc(80);
		t2 = (char*)malloc(80);
		t3 = (char*)malloc(80);	
		
		fgets(buff,80,stdin);
		
		sscanf(buff, "%s %s %s", t1, t2, t3);
		
		if(strcmp(t1, "pause") == 0)
			exit(0);
		if(strcmp(t1, "count") == 0)
			count(t2, t3);
		else
		{
			pid = fork();
			
			if(pid < 0)
				printf("\nChild Process is NOT Created!\n");
			else if(pid == 0)
			{
				execlp("ls", "ls", NULL);
				system(buff);
			}
			else
			{
				wait(NULL);
				exit(0);
			}
		}
		
	}
	
}
