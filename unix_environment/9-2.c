#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;
	pid_t sid;

	printf("parent : pid = %d, ppid = %d, pgrp = %d, tpgrp = %d\n"\
	, getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_FILENO));
	fflush(stdout);
	pid = fork();
	if(pid < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	else if (pid > 0)
	{
		exit(0);
	}
	//sleep(3);
	printf("child : pid = %d, ppid = %d, pgrp = %d, tpgrp = %d\n"\
        , getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_FILENO));
        fflush(stdout);
	sid = setsid();
	if(sid < 0)
	{
		printf("setsid error\n");
		exit(1);
	}
	printf("child new session: pid = %d, ppid = %d, pgrp = %d, tpgrp = %d\n"\
        , getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_FILENO));
        fflush(stdout);
	printf("never printf1\n");
	pid = fork();
	if(pid < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	else if(pid != 0)
	{
		exit(0);
	}
	printf("never printf2\n");
	
	return 0;
}

