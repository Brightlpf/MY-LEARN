#include <stdio.h>
#define BUF 256

char str[BUF];
int my_atoi(const char *str);

int main(void)
{
	char *pstr;
	int result;
	
	puts("Enter a string (number): ");
	while(gets(str) && str[0] != '\0')
	{
		result = my_atoi(str);
		
		printf("%d\n", result);
	}
	puts("Done.\n");
	return 0;
}
