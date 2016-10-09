#include <apue.h>
#include <signal.h>

void sig_int(int signo);
volatile sig_atomic_t quitflag;

int main(void)
{
	struct sigaction act, oact;
	sigset_t newmask, oldmask, zeromask;
	
	sigemptyset(&act.sa_mask);
	act.sa_handler = sig_int;
	act.sa_flags = 0;
	if (sigaction(SIGINT, &act, &oact) < 0)
		err_sys("signal SIGINT error");
	if (sigaction(SIGQUIT, &act, &oact) < 0)
		err_sys("signal SIGINT error");
	
	sigemptyset(&newmask);
	sigemptyset(&zeromask);
	sigaddset(&newmask, SIGQUIT);
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
	{
		err_sys("sigprocmask error");
	}
	while(quitflag == 0)
	{
		sigsuspend(&zeromask);
	}
	
	quitflag = 0;
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	
	printf("program exit...\n");
	exit(0);
}

void sig_int(int signo)
{
	if(signo == SIGINT)
	{
		printf("interrupt\n");
	}
	else if(signo == SIGQUIT)
	{
		quitflag = 1;
	}
}
