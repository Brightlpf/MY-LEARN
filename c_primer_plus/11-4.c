#include <stdio.h>
#define BUF 256
char line[BUF];
char * my_strchr(const char *str, char ch);

int main(void)
{
	char ch;
	char *ptr = NULL;
	
	while(fgets(line, BUF, stdin) != NULL)
	{
		if((ptr = my_strchr(line, 'y')) != NULL)
		{
			puts(ptr);
		}
		else
		{
			puts("Not found!");
		}
	}
	return 0;
}

char * my_strchr(const char *str, char ch)
{
	if (NULL == str)
	{
		return NULL;
	}
	while(*str != '\0')
	{
		if(*str == ch)
			return str;
		else
			str++;
	}
	return NULL;
}
