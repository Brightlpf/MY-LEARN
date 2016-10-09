#include <apue.h>

static void sig_proc(int signo);

int main(void)
{
	if(signal(SIGUSR1, sig_proc) == SIG_ERR)
		err_quit("can't catch SIGUSR1");
	if(signal(SIGUSR2, sig_proc) == SIG_ERR)
		err_quit("can't catch SIGUSR2");
	for(;;)
		pause();
}

static void sig_proc(int signo)
{
	if(signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if(signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		printf("received signo %d\n", signo);
}
