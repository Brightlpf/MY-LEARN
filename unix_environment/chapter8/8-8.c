#include <apue.h>
#include <sys/wait.h>

int main(void)
{
	pid_t  pid;
	
	if((pid = fork()) < 0)
		err_sys("fork first child error");
	else if(pid == 0)
	{
		if((pid = fork()) < 0)
			err_sys("fork second child err");
		else if( pid > 0)
		{
			printf("exiting the first child process\n");
			exit(0);
		}
		
		sleep(2);
		printf("second child process, parent pid = %d\n", (long)getppid());
		exit(0);
	}
	
	if(waitpid(pid, NULL, 0)!= pid)
		err_sys("waitpid error");
	
	printf("exiting the father process \n");
	exit(0);
}
