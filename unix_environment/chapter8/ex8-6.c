#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;
	
	if((pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	else if(pid == 0)
		exit(0);
	
	sleep(3);
	system("ps -u");
	exit(0);
}
