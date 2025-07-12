#include<stdio.h>
#include<string.h>

struct input
{
	char pname[10];
	int bt, at, tbt, ft;
}tab[10];

struct gantt
{
	int start, end;
	char pname[10];
}g[50],g1[20];

int n, i, k, time, prev;

void getinput()
{
	printf("\nEnter No. of Processes: ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		printf("\nProcess Name: ");
		scanf("%s", tab[i].pname);
		
		printf("\nArrival Time: ");
		scanf("%d", &tab[i].at);
		
		printf("\nBurst Time: ");
		scanf("%d", &tab[i].bt);
		
	}
}

void printinput()
{
	printf("\nPname\tAT\tBT");
	for(i = 0; i < n; i++)
	{
		printf("\n%s\t%d\t%d",tab[i].pname,tab[i].at,tab[i].bt);
	}
}

void sort()
{
	int j;
	struct input temp;
	
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < n-1; j++)
		{
			if(tab[j].at > tab[j+1].at)
			{
				temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp;
			}
		}
	}
}

int main()
{
	getinput();
	
	printf("\n\nEntered data is:");
	printinput();
	sort();
	printf("\n\nData after sorting: ");
	printinput();

	return 0;	
}
