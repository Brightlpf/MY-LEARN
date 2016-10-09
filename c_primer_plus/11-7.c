#include <stdio.h>
#define BUF 256

char str[BUF];
char substr[BUF];
char * string_in(char *str, char *substr);

int main(void)
{
	char *ptr = NULL;
	while(gets(str) && str[0] != '\0')
	{
		printf("Enter substr please: \n");
		gets(substr);
		ptr = string_in(str, substr);
		if(ptr != NULL)
		{
			puts(ptr);
		}
		else
		{
			puts("Not found!\n");
		}
	}
	printf("Done.\n");
}

char * string_in(char *str, char *substr)
{
	/*
	char *ptr = NULL;
	char *psubstr = substr;
	
	if(str == NULL || substr == NULL)
	{
		return NULL;
	}
	while(*str)
	{
		substr = psubstr;
		while(*str != '\0' && *str != *substr)
			str++;
		if(*str == '\0')
			return NULL;
		ptr = str;	
		while(*str != '\0' && *str == *substr)
		{
			str++;
			substr++;
		}
		;
		if(*substr == '\0')
		{
			return ptr;
		}
	}
	
	return NULL;
	*/
	int i;
	for(i = 0; str[i] != '\0'; i++)  
    {  
        int tem = i; //tem保留主串中的起始判断下标位置   
        int j = 0;  
        while(str[i++] == substr[j++])  
        {  
            if(substr[j] == '\0')  
            {  
                return &str[tem];  
            }  
        }  
        i = tem;  
    }  
  
    return NULL; 
}
