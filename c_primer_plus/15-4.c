#include <stdio.h>

char * itobs(int n, char * ps);
int getbitvalue(int n, int index);

int main(void)
{
	int num;
	int index;
	int ret;
	char ps[8 * sizeof(int) + 1];
	
	printf("Please input a number : ");
	while( scanf("%d", &num)==1 && num > 0)
	{
		printf("Please input the index: ");
		scanf("%d", &index);
		while(getchar() != '\n')
			continue;
		ret = getbitvalue(num, index);
		printf("%s : index = %d, ret = %d\n", itobs(num, ps), index, ret);
		puts("agin...");
	}
	puts("Done.");
	return 0;
}

char * itobs(int n, char * ps)
{
	int i;
	int size = 8 * sizeof(int);
	for(i = size -1; i >=0; i--)
	{
		ps[i] = (n & 01) + '0';
		n >>= 1;
	}
	ps[size] = '\0';
	return ps;
}

int getbitvalue(int n, int index)
{
	int mask = 01;
	
	while(index--)
	{
		mask <<= 1;
	}
	if((n & mask) == mask)
		return 1;
	
	return 0;
}
