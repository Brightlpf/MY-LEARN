#include <stdio.h>

int main(void)
{
	char ch;
	char buffer[1024];
	int num = 0;
	int i;
	
	printf("input some text,end with EOF:\n");
	while((ch = getchar())!=EOF)
	{
		buffer[num++] = ch;
	}
	printf("\n");
	
	for(i = 0; i < num; i++)
	{
		ch = buffer[i];
		if(ch < ' ')
		{
			if (ch == '\n')
			{
				printf("%-4c-%-5d","\n", ch);
			}
			else if (ch == '\t')
			{
				printf("   \\t-%-5d",ch);
			}
			else printf("^%-4c-%-5d", ch+64, ch);
		}
		else
		{
			printf("%4c-%-5d", ch, ch);
		}
		if((i + 1)%8 == 0)
		{
			printf("\n");
		}
	}
	return 0;
}
