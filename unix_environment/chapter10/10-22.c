#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

static void sig_int(int);
static void pr_mask(const char * str);

int main(void)
{
	sigset_t newmask, oldmask, waitmask;
	
	pr_mask("program start: ");
	
	if(signal(SIGINT, sig_int) == SIG_ERR)
		perror("signal error");
	sigemptyset(&waitmask);
	sigaddset(&waitmask, SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);
	
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		perror("sigprocmask error");
	
	//critical region of code
	pr_mask("in critical region: ");
	
	if(sigsuspend(&waitmask) != -1)
		perror("sigsuspend error");
	
	pr_mask("After return from suspend: ");
	
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		perror("sigprocmask error");
	
	pr_mask("program exit: ");
	
	exit(0);
}

static void sig_int(int signo)
{
	pr_mask("\nin sig_int: ");
}

static void pr_mask(const char * str)
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
