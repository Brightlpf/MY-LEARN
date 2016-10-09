#include <stdio.h>
#define BUF 256

char str1[BUF];
char str2[BUF];
char * my_strncpy(char *des, const char * src, int n);

int main(void)
{
	char *pstr = NULL;
	int n;
	int ch;
	
	while(gets(str1) && str1[0] != '\0')
	{
		printf("Enter a number: ");
		if(scanf("%d", &n) != 1)
		{
			return 1;
		}
		while((ch = getchar()) != '\n')
			continue;
		pstr = my_strncpy(str2, str1, n);
		if(pstr == NULL)
		{
			
		}
		puts("get it!");
		puts(str2);
	}
	return 0;
}

char * my_strncpy(char *des, const char * src, int n)
{
	char *p = des;
	int count = 0;
	
	if(NULL == des || NULL == src)
	{
		return NULL;
	}
	while( count < n && (*des++ = *src++) != '\0' )
	{
		count++;
	}
	if(*des != '\0')
	{
		*des = '\0';
	}
	return des;
}
