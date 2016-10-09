#include <stdio.h>
#include <stdlib.h>

unsigned int rotate(unsigned int num, int n);
char * itobs(unsigned int n, char * ps);

int main(void)
{
	unsigned int num;
	int n;
	unsigned int result;
	char ps[8 * sizeof(unsigned int) + 1]; 
	
	printf("Please input a num and number of retate: ");
	while(scanf("%d %d", &num, &n) == 2)
	{
		while(getchar() != '\n')
			continue;
		
		result = rotate(num, n);
		printf("result = %d\n", result);
		printf("input: %s\n", itobs(num, ps));
		printf("output: %s\n", itobs(result, ps));
		puts("next...");
	}
}

unsigned int rotate(unsigned int num, int n)
{
	if (n < 0 )
	{
		exit(1);
	}
	if (n == 0)
		return num;
	unsigned int temp = 0;
	unsigned int mask = 01;
	int nback = n;
	
	while(--nback)
	{
		mask |= mask <<1;
	}
	printf("mask = %d\n", mask);
	temp = mask & num;
	printf("temp = %d\n", temp);
	return (num >> n) | (temp << (8 *sizeof(unsigned int) - n));
}

char * itobs(unsigned int n, char * ps)
{
	int i;
	int size = 8 * sizeof(unsigned int);
	
	for(i = size -1; i >= 0; i--)
	{
		ps[i] = (n & 01) + '0';
		n >>= 1;
	}
	ps[size] = '\0';
	return ps;
}
