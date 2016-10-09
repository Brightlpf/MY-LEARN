#include <stdio.h>
#define NUM 26

int main(void)
{
	char alphabet[NUM];
	int i;
	
	for(i = 0; i < NUM; i++)
	{
		alphabet[i] = 'a' + (char)i;
	}
	printf("%s\n", alphabet);
	
	return 0;
}