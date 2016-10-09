#include <stdio.h>
#define TEN 10

int main(void)
{
	int n;
	int i;
	
	printf("Please enter a number: ");
	scanf("%d", &n);
	for(i = n; i < n+10; i++)
	{
		printf("%d\t", i);
	}
	printf("\n");
	
	return 0;
}