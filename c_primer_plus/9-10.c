#include <stdio.h>
long fib(int n);

int main(void)
{
	int n;
	long result;
	
	printf("Please enter a number: ");
	if(scanf("%d", &n) != 1)
	{
		printf("Input valid!\n");
		return 1;
	}
	result = fib(n);
	printf("result: fib(%d) = %d\n", n, result);
}

long fib(int n)
{
	int i;
	long current;
	long prev = 1;
	long beforeprev = 1;
	
	for(i = 2; i < n; i++)
	{
		current = prev + beforeprev;
		beforeprev = prev;
		prev = current;
		printf("fib[%d] = %d\n", i + 1, current);
	}
	return current;
}
