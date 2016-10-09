#include <apue.h>
#include <fcntl.h>

int my_dup2(int filedes1, int filedes2);
int main(void)
{
	int fd;
	int fd_new;
	int fd_test;
	int nbyte;
	
	
	fd = open("file_cpy.c", O_RDWR);
	if(fd < 0)
		err_quit("open file_cpy.c err");
	
	fd_new = open("3-1.c", O_RDWR);
	if(fd_new < 0)
		err_quit("open 3-1.c err");
	printf("fd = %d, fd_new = %d\n", fd, fd_new);
	
	fd_test = open("3-4.c", O_RDONLY);
	if(fd_new < 0)
		err_quit("open 3-1.c err");
	printf("Test fd_test = %d\n", fd_test);
	my_dup2(fd, fd_new);
	printf("After dup2: fd = %d, fd_new = %d\n", fd, fd_new);
	
	if((nbyte = write(fd_new, "// test mydup2 hello world\n   ", 27)) !=27)
	{
		printf("write failed. nbyte = %d\n", nbyte);
	}
	
	exit(0);
}

int my_dup2(int filedes1, int filedes2)
{
	int fd[filedes2];
	int count = 0;
	
	if(filedes1 < 0 || filedes2 < 0)
	{
		printf("my_dup2: paramter err\n");
		return -1;
	}
	if(filedes1 == filedes2)
	{
		return filedes2;
	}
	close(filedes2);
	while(count < filedes2)
	{
		fd[count] = dup(filedes1);
		if(fd[count] < 0)
		{
			return -1;
		}
		if(fd[count] == filedes2)
			break;
		else
		{
			count++;
		}
		
	}
	if(fd[count] != filedes2)
	{
		int i;
		for(i = 0; i <= count; i++)
		{
			close(fd[count]);
		}
	}
	
	return filedes2;
}
