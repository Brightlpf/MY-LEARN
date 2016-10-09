#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>

void pr_mask(const char * str);
static void sig_usrl(int );
static void sig_alarm(int );
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;

int main(void)
{
	if(signal(SIGUSR1, sig_usrl) == SIG_ERR)
		perror("sinal(SIGUSRL) error");
	
	if(signal(SIGALRM, sig_alarm) == SIG_ERR)
		perror("sinal(SIGALRM) error");
	
	pr_mask("starting main: ");
	
	if(sigsetjmp(jmpbuf, 1))
	{
		pr_mask("ending main: ");		
		exit(0);
	}
	canjump = 1;
	while(1)
	{
		pause();
	}
}

static void sig_usrl(int signo)
{
	time_t starttime;
	
	if(canjump == 0)
		return;
	pr_mask("starting sig_usrl: ");
	alarm(3);
	starttime = time(NULL);
	while(1)
	{
		if(time(NULL) > starttime + 5)
			break;
	}
	pr_mask("finishing sig_usrl: ");
	canjump = 0;
	siglongjmp(jmpbuf, 1);
}

static void sig_alarm(int signo)
{
	pr_mask("in sig_alarm: \n");
}

void pr_mask(const char * str)
{
	sigset_t sigset;
	int errno_save;
	
	errno_save = errno;
	if(sigprocmask(0, NULL, &sigset) < 0)
		perror("sigpromask error");
	else
	{
		printf("%s", str);
		if(sigismember(&sigset, SIGINT))
			printf(" SIGINT");
		if(sigismember(&sigset, SIGQUIT))
			printf(" SIGQUIT");
		if(sigismember(&sigset, SIGUSR1))
			printf(" SIGUSR1");
		if(sigismember(&sigset, SIGALRM))
			printf(" SIGALRM");
		printf("\n");
	}
	
	errno = errno_save;
}
