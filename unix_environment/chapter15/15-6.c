#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <error.h>
#include <sys/wait.h>
#include <string.h>

#define LINEMAX 1024

char pipebuf[LINEMAX];
char childbuf[LINEMAX];

int main(void)
{
	int fd[2];
	pid_t pid;
	int ret;

	
	if((ret = pipe(fd)) < 0)
	{
		perror("pipe error");
		exit(1);
	}
	if((pid = fork()) < 0)
	{
		perror("fork error");
		exit(1);
	}
	if(pid > 0)
	{
		close(fd[0]);
		while (read(STDIN_FILENO, pipebuf, LINEMAX) > 0)
		{
			write(fd[1], pipebuf, LINEMAX);
			//memset(pipebuf, 0, LINEMAX);
		}			
		printf("wait child process...\n");	
		close(fd[1]);
		waitpid(pid, NULL, 0);
	}else
	{
		close(fd[1]);
		if(fd[0]!= STDIN_FILENO)
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execl("/bin/more", "more", (char *)0);	
		/*
		int nbyte;
		
		close(fd[1]);
		while((nbyte = read(fd[0], childbuf, LINEMAX)) > 0)
		{
			write(STDOUT_FILENO, childbuf, nbyte);
			memset(childbuf, 0, LINEMAX);
		}
		*/	
		exit(0);
	}
	exit(0);
}
