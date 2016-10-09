#include <apue.h>
#include <signal.h>

void sig_quit(int signo);

int main(void)
{
	sigset_t newmask, oldmask, pendmask;
	
	if(signal(SIGQUIT, sig_quit) == SIG_ERR)
	{
		err_sys("can't catch SIGQUIT");
	}
	//block sigquit, save current sig
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIGBLOCK ERROR");
	sleep(5);//wait for sigquit
	
	sigpending(&pendmask);
	if(sigismember(&pendmask, SIGQUIT))
	{
		printf("SIGQUIT is pengding\n");
	}
	else 
	{
		printf("SIGQUIT is not pengding\n");
	}
	//restore sigmask
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	printf("cancle sig bock\n");
	
	sleep(5);
	exit(0);
}

void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if(signal(SIGQUIT, sig_quit) == SIG_ERR)
	{
		err_sys("can't catch SIGQUIT");
	}
}

