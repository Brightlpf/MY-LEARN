#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <error.h>

int main(void)
{
	int fd[2];
	pid_t pid;
	int ret;
	char pipebuf[1024];
	
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
		write(fd[1], "Hello world\n", 12);
	}else
	{
		close(fd[1]);
		ret = read(fd[0], pipebuf, 12);
		write(STDOUT_FILENO, pipebuf, ret);
	}
	exit(0);
}
