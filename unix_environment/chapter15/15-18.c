#include <apue.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#define LINE_MAX 1024

char buf[LINE_MAX];

/*
int main(void)
{
	pid_t pid;
	int fd1[2];
	int state;
	
	//只使用一个管道
	if(pipe(fd1) < 0 || pipe(fd2) < 0)
	{
		err_sys("pipe error");
	}
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		close(fd1[0]);
		if(STDOUT_FILENO != fd1[1])
		{
			dup2(fd1[1], STDOUT_FILENO);
		}
		//printf("child: exec add2.....\n");
		execl("./add2", "add2", (char *)0);
		exit(-127);
	}
	
	//close(fd2[1]);
	close(fd1[1]);
	if(STDIN_FILENO != fd1[0])
	{
		dup2(fd1[0], STDIN_FILENO);
	}
	printf("parent: read from pipe1.....\n");
	read(fd1[0], buf, LINE_MAX);
	write(STDOUT_FILENO, buf, strlen(buf));
	wait(&state);
	printf("child return : %d\n", state);
	exit(0);
}
*/

int main(void)
{
	pid_t pid;
	int fd1[2], fd2[2];
	int state;
	int n;
	
	if(pipe(fd1) < 0 || pipe(fd2) < 0)
	{
		err_sys("pipe error");
	}
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		//关闭管道1的写，管道2的读，重新设置标准输入输出为管道1，管道2
		close(fd1[1]);
		close(fd2[0]);
		if(STDIN_FILENO != fd1[0])
			dup2(fd1[0], STDIN_FILENO);
		if(STDOUT_FILENO != fd2[1])
			dup2(fd2[1], STDOUT_FILENO);
		
		execl("./add2", "add2", (char *)0);
		exit(-127);
	}
	//关闭管道1的读，管道2的写
	close(fd1[0]);
	close(fd2[1]);
	
	//从标准输入读取两个操作数, 写到管道1中
	read(STDIN_FILENO, buf, LINE_MAX);
	write(fd1[1], buf, LINE_MAX);
	
	//从管道2中读取操作结果，写到标准输出
	//先将buf重新清空，或者在字符串后面添加字符串结束符
	//memset(buf, 0, LINE_MAX);
	if((n = read(fd2[0], buf, LINE_MAX)) > 0)
		write(STDOUT_FILENO, buf, n);
	buf[n] = 0;
	wait(&state);
	printf("child return : %d\n", state);
	exit(0);
}
