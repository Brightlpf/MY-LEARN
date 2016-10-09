#include <stdio.h>

int main(void)
{
	int num;
	int count =0;
	int i;
	int size = 8 * sizeof(int);
	int mask = 0x01;
	while(scanf("%d", &num) == 1)
	{
		count = 0;
		mask = 0x01;
		for(i = 0; i < size; i++)
		{
			if((num & mask) == mask)
				count++;
			mask <<= 1;
		}
		
		printf("have %d bit on.\n", count);
		while(getchar() != '\n')
			continue;
	}
}
