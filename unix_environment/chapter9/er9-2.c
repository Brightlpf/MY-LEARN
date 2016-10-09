#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

void (*signal(int signo, void (*func)(int)))(int);
int main(void)
{
	pid_t pid;
	char c;
	
	if((pid = fork()) < 0)
	{
		printf("fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("befor session: \nchild: pid = %ld, ppid = %ld, pgrp = %ld\n", (long)getpid(), (long)getppid(), (long)getpgrp());
		if((pid = setsid()) != -1)
			printf("After session: \nchild: pid = %ld, ppid = %ld, pgrp = %ld\n", (long)getpid(), (long)getppid(), (long)getpgrp());
		if(read(STDIN_FILENO, &c, 1) != 1)
			printf("read error %d on controlling TTY\n", errno);
		while(1);
		exit(0);
	}
	printf("father: pid = %ld, ppid = %ld, pgrp = %ld\n", (long)getpid(), (long)getppid(), (long)getpgrp());
	wait(NULL);
	exit(0);
}
