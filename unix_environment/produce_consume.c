#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

/*
*child : consume
*/
volatile sig_atomic_t flag;
static sigset_t zeromask;

void sig_handler(int signo);
void waitparent(void);
void tellparent(pid_t pid);
void waitchild(void);
void tellchild(pid_t pid);

int main(void)
{
	pid_t pid;
	
	struct sigaction act, oact;
	
	sigemptyset(&zeromask);
	act.sa_handler = sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if(sigaction(SIGUSR1, &act, &oact) < 0)
	{
		printf("signal SIGUSR1 error");
	}
	if(sigaction(SIGUSR2, &act, &oact) < 0)
	{
		printf("signal SIGUSR1 error");
	}
	
	if((pid = fork()) < 0)
	{
		perror("fork error");
	}
	else if (pid == 0)
	{
		while(1)
		{
			waitparent();
			printf("child consuming ......\n");
			tellparent(getppid());
		}	
	}
	else
	{
		while(1)
		{
			printf("parent produce ......\n");
			sleep(3);
			tellchild(pid);
			waitchild();
		}
	}
}

void sig_handler(int signo)
{
	flag = 1;
}

void waitparent(void)
{
	while(flag == 0)
		sigsuspend(&zeromask);
	flag = 0;
}
void tellparent(pid_t pid)
{
	if(kill(pid, SIGUSR1) < 0)
		printf("send msg to patent failed\n");
}
void waitchild(void)
{
	while(flag == 0)
		sigsuspend(&zeromask);
	flag = 0;
}
void tellchild(pid_t pid)
{
	if(kill(pid, SIGUSR2) < 0)
		printf("send msg to child failed\n");
}
