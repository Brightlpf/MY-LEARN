#include <stdio.h>
#include <ctype.h>

int getIndexOfAlpha(char ch);
int main(void)
{
	int ch;
	int index = 0;
	
	printf("Please enter a character: ");
	while((ch = getchar()) != EOF)
	{
		index = getIndexOfAlpha((char)ch);
		if(index == -1)
		{
			printf("%c is not alphabet\n", ch);
			continue;
		}
		printf("The index of %c is %d .\n", ch, index);
		while(getchar() != '\n');
	}
	return 0;
}

int getIndexOfAlpha(char ch)
{
	int index;
	
	if(isalpha(ch))
	{
		index = toupper(ch) - 'A';
	}
	else
	{
		index = -1;
	}
	return index;
}
