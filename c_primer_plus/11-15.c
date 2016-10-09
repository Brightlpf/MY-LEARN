#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void display(int ch, char * option);

int main(int argc, char * argv[])
{
	int ch;
	
	if(argc > 2)
	{
		printf("Useage : %s [-p | -u | -l]\n", argv[0]);
		exit(1);
	}
	
	while((ch = getchar()) != EOF)
	{
		if(argc == 1)
		{
			display(ch, "-p");
		}
		else
		{
			display(ch, argv[argc - 1]);
		}		
	}
	puts("Done.\n");
	return 0;
}

void display(int ch, char * option)
{
	int ret;
	
	if(strncmp("-p", option, 2) == 0)
	{
		ret = putchar(ch);
	}
	else if (strncmp("-u", option, 2) == 0 )
	{
		ret = putchar(toupper(ch));
	}
	else if (strncmp("-l", option, 2) == 0)
	{
		ret = putchar((tolower(ch)));
	}
	else
	{
		printf("%s invalid.\n", option);
		exit(1);
	}
	
	if(ret ==EOF)
	{
		printf("output error:%m\n");
		exit(1);
	}
}
