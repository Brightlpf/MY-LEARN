#include <apue.h>
#include <sys/wait.h>

static void sig_cld(int signo);

int main()
{
	pid_t pid;
	
	if(signal(SIGCHLD, sig_cld) == SIG_ERR)
		perror("signal error");
	pid = fork();
	if(pid < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		sleep(2);
		_exit(0);
	}
	pause();
	exit(0);
}

static void sig_cld(int signo)
{
	int status;
	pid_t pid;
	
	printf("receive SIG_CHLD\n");
	
	if(signal(SIGCHLD, sig_cld) == SIG_ERR)
		perror("signal error");
	if((pid = wait(&status)) < 0)
		perror("wait error");
	printf("pid = %d\n", pid);
}
