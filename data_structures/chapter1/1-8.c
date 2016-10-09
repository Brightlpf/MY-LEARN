#include <stdio.h>

long fib(int n);
long fib_for(int n);

int main()
{
	int n;
	printf("Enter a interger: ");
	scanf("%d", &n);
	while(n >= 0)
	{
		//printf("fib(%d) = %ld\n", n, fib(n));
		printf("fib(%d) = %ld\n", n, fib_for(n));
		printf("Enter a interger: ");
		scanf("%d", &n);
	}

	return 0;
}

long fib(int n)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
	{
		return fib(n-1) + fib(n-2);
	}
}

long fib_for(int n)
{
	int i;
	int arr[n + 1];
	
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
	{
		arr[0] = 0;
		arr[1] = 1;
		
		for(i = 2; i <= n; i++)
		{
			arr[i] = arr[i-1] + arr[i-2];
			printf("arr[%d] = %d, arr[%d] = %d, arr[%d] = %d\n", i, arr[i], i-1, arr[i-1], i-2, arr[i-2]);
		}
	}

	return arr[i];
}
