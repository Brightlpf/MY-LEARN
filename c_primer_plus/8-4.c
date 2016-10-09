#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int words = 0,  count = 0;
	char ch;
	int inword = 0;
	
	while((ch = getchar()) != EOF)
	{
		if(!ispunct(ch))
		{
			if(!isspace(ch))
			{
				count++;
				inword = 1;
			}
		}
		
		if(isspace(ch) || ispunct(ch))
		{
			if(inword == 1)
			{
				words ++;
				inword = 0;
			}
		}
	}
	
	printf("words = %d, %.1f char per word.\n", words, count/(words * 1.0));
	return 0;	
}
