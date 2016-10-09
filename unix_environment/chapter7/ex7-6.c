#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long *ptr;
	long (*parr)[sizeof(long *)];
	//long * arr[];
	//long **parr;
	int i;
	
	ptr = (long *)calloc(100, sizeof(long));
	parr =(long (*)[sizeof(long *)])calloc(100, sizeof(long));
	for(i = 0; i < 5; i++)
	{
		printf("ptr[%d] = %d	", i, ptr[i]);
	}
	printf("\n");
	for(i = 0; i < 5; i++)
	{
		if(parr[i] == NULL)
		{
			printf("ptr[%d] = NULL	", i);
		}	
		else
			printf("%s", ptr[i]);
	}
	printf("\n");
}