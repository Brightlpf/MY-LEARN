#include <stdio.h>

int main(void)
{
	int i, j;//i ctrl lines, j ctrl alphabets
	int space = 0;
	char c, ch;
	int n;
	
	printf("please enter a upper alphabet: ");
	while(1)
	{
		scanf("%c", &c);
		n = c -'A' + 1;
		
		if(n < 1 || n > 26)
		{
			printf("range from A - Z\n");
			return 1;
		}
		
		for(i = 0; i < n; i++)
		{
			//print space
			for(space = 0; space < n -1 -i; space++)
			{
				printf(" ");
			}
			//print alph by raise
			for(j = 0; j <= i; j++)
			{
				printf("%c", 'A' + j);
			}
			//print alph by fall
			for(j = 0; j < i; j ++)
			{
				printf("%c", 'A'+i-1-j);
			}
			//print space
			for(space = 0; space < n -1 -i; space++)
			{
				printf(" ");
			}
			printf("\n");
		}
		while(getchar()!='\n');
	}
	return 0;
}
