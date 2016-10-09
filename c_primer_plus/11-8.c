#include <stdio.h>
#include <string.h>
#define BUF 256

char str[BUF];

int reversed(char *str);

int main(void)
{
	char *pstr;
	
	while(gets(str) && str[0] != '\0')
	{
		reversed(str);
		puts(str);
	}
	puts("Done.\n");
	return 0;
}

int reversed(char *str)
{
	char temp[BUF];
	int i;
	int len;
	
	len = strlen(str);
	for(i = 0; i < len; i++ )
	{
		temp[len-i-1] = str[i];
	}
	
	for(i = 0; i < len; i++)
	{
		str[i] = temp[i];
	}
	str[len] = '\0';
	
	return 0;
}