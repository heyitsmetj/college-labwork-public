#include <stdio.h>
#include <time.h>

void sample_instructions()
{
	long long total = 0;
	int i;
	
	for(i = 0;i < 10000000;i++)
	{
		total += i;
	}
	
	printf("\nTotal: %lld\n",total);
}

int main()
{
	
	clock_t start_time = clock();
	sample_instructions();
	clock_t end_time = clock();
	
	double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
	
	printf("\nExecution Time: %f seconds.\n", execution_time);
	
	return 0;
}
