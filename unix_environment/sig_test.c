#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signo);

int main(void)
{
	int i;
	
	signal(SIGINT, sig_handler);
	for(i = 0; i < 10; i++)
	{
		printf("*");
		fflush(NULL);
		sleep(1);
	}
	return 0;
}

void sig_handler(int signo)
{
	printf("!");
	fflush(NULL);
}
