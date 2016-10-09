#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char ** environ;

int main(void)
{
	char value[20];
	char *ptr;
	int i;
	
	ptr = getenv("HOME");
	strcpy(value, ptr);
	printf("HOME = %s\n", value);
	
	printf("environ table: \n");
	for(i = 0; environ[i] != NULL; i++)
	{
		puts(environ[i]);
	}
}
