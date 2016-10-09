#include <apue.h>
#include <setjmp.h>
#include <signal.h>

static jmp_buf env_alrm;

unsigned int sleep2(unsigned int seconds);
void sig_handler(int signo);
void sig_alrm(int signo);

int main(void)
{
	unsigned int unslept;
	
	if(signal(SIGINT, sig_handler) == SIG_ERR)
	{
		err_sys("signale err");
	}
	unslept = sleep2(5);
	printf("sleep2 return : %d\n", unslept);	
	return 0;
}

void sig_handler(int signo)
{
	int i, j;
	volatile int k;
	printf("starting sig_int: \n");
	
	for(i = 0; i < 300000; i++)
		for(j = 0; j < 4000; j++)
				k += i * j;
	
	printf("quit sig_int: \n");
}

unsigned int sleep2(unsigned int seconds)
{
	
	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
	{
		return seconds;
	}
	
	if(setjmp(env_alrm) == 0)
	{
		alarm(seconds);
		pause();
	}
	return (alarm(0));
}

void sig_alrm(int signo)
{
	longjmp(env_alrm, 1);
}
