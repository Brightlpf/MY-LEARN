#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

//extern char *sys_siglist[];
int mysig2str(int signo, char * str);
//char * strsignal(int signo);
int main(void)
{
	char *str;
	int i;
	
	str = (char *)malloc(sizeof(char) * 100);
	if(NULL == str)
	{
		printf("malloc failed\n");
		exit(1);
	}
	for(i = 1; i < 32; i++)
	{
		if(mysig2str(i, str) == -1)
		{
			printf("sig2str failed\n");
			exit(1);
		}
		printf("%d: %s\n", i, str);
	}
	return 0;
}

int mysig2str(int signo, char * str)
{
	if ((signo > 64)||(NULL == str))
	{
		printf("str is null\n");
		return -1;
	}
	strcpy(str, sys_siglist[signo]);

	return 0;
}
