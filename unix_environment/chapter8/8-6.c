#include <apue.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	pid_t child_pid;
	
	int status;
	
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		exit(7);
	}
	printf("child 1 : pid = %d\n", child_pid);
	if(waitpid(pid, &status, 0) != pid)
		err_sys("wait error");
	pr_exit(status);
	
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
		abort();
	
	if(wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
	
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
		status /=0;
	
	if(wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);
	
	exit(0);
}
