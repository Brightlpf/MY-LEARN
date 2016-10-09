#include <stdio.h>
#include <ctype.h>

int my_atoi(const char *str)
{
	int num = 0;
	
	while(*str)
	{
		if(isdigit(*str))
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		else
		{
			return 99999999;
		}
	}
	return num;
}
