#include <stdio.h>
#include <math.h>

int main()
{
	int arr[8];
	int i;
	
	for(i = 0; i< 8; i++)
	{
		arr[i] = pow(2, i);
	}
	
	i = 0;
	do
	{
		printf("%d\t", arr[i++]);
	}while(i < 8);
	printf("\n");

	return 0;
}
