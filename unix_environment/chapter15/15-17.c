#include <stdlib.h>
#include <stdio.h>


int main(void)
{
	int add1, add2;
	int sum;
	
	fscanf(stdin, "%d %d", &add1, &add2);
	sum = add1 + add2;
	fprintf(stdout, "%d\n", sum);
	return 0;
}
