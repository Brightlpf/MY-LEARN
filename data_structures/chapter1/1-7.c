#include <stdio.h>

long fact(int n);
long fact_for(int n);
int main(void)
{
	int n;
	printf("Enter a integer: ");
	scanf("%d", &n);
	
	if(n < 0)
		return 1;
	//printf("%d! = %ld\n", n, fact(n));
	printf("%d! = %ld\n", n, fact_for(n));
	return 0;
}

long fact(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
		return (n * fact(n - 1));
}

long fact_for(int n)
{
	int i, sum = 1;
	while(n > 0)
		sum *= n--;
	return sum;
}