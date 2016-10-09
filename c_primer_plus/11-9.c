#include <stdio.h>
#include <ctype.h>

int drop_space(char *str)
{
	char *pos;
	
	if(str == NULL)
	{
		puts("param err");
		return 1;
	}
	
	while(*str)
	{
		if(isspace(*str))
		{
			pos = str;
			//while((*prev++ = *str++));
			while(*pos = *(pos + 1))
				pos++;
		}
		else
		{
			str++;
		}	
	}
	return 0;
}
