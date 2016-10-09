#include <stdio.h>

long ackerman(int m, int n);
long ackerman_for(int m , int n);

int main()
{
	int m, n;
	
	printf("Enter m , n: ");
	scanf("%d %d", &m, &n);

	while(m >= 0 && n >= 0)
	{
		//printf("A(%d, %d) = %ld\n", m, n, ackerman(m, n));
		printf("A(%d, %d) = %ld\n", m, n, ackerman_for(m, n));
		printf("Enter m , n: ");
		scanf("%d %d", &m, &n);
	}
	
	return 0;
}

long ackerman(int m, int n)
{
	if(m == 0)
		return (n + 1);
	else if(n == 0)
		return ackerman(m-1, 1);
	else
	{
		return (ackerman(m-1, ackerman(m, n -1)));
	}
}

long ackerman_for(int m , int n)
{
	if(m == 0)
	{
		return n + 1;		
	}
	else if(n == 0)
	{
		
	}
}