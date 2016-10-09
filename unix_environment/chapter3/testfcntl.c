#include <apue.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int save_fd;
	int fd_flag;
	int nbyte;
	
	//复制文件描述符
	printf("1: copy file description.\n");
	write(STDOUT_FILENO, "Write stdout test\n", 18);
	save_fd = dup(STDOUT_FILENO);
	close(STDOUT_FILENO);
	fd = fcntl(save_fd, F_DUPFD, 0);
	if((nbyte = write(fd, "fd -> stdout\n", 13)) != nbyte)
	{
		err_sys("write err");
	}
	printf("nbyte = %d.\n", nbyte);
	//close(fd);
	
	//获取、设置文件描述标识
	printf("\n\n2: set filedes flag.\n");
	fd_flag = fcntl(STDOUT_FILENO, F_GETFD, 0);
	printf("stdout fd_flag = %d, ", fd_flag);
	fd_flag |= FD_CLOEXEC;
	printf("set FD_CLOEXEC: %d\n", FD_CLOEXEC);
	fcntl(STDOUT_FILENO, F_SETFD, fd_flag);
	sleep(5);
	//
	fd_flag &= ~FD_CLOEXEC;
	printf("cancel FD_CLOEXEC: fd_flag = %d\n", fd_flag);
	fcntl(STDOUT_FILENO, F_SETFD, fd_flag);
	
	
	//获取、设置文件状态标识
	printf("\n\n3: get filestate flag.\n");
	printf("Get file state flag. O_ACCMODE = %d\n", O_ACCMODE);
	fd_flag = fcntl(STDOUT_FILENO, F_GETFL, 0);
	switch(fd_flag & O_ACCMODE)
	{
		case O_RDONLY:
			printf("stdout: read only.\n");
			break;
		case O_WRONLY:
			printf("stdout: write only.\n");
			break;
		case O_RDWR:
			printf("stdout: rd + wr.\n");
			break;
		default:
			printf("unkown mode.\n");
			break;
	}
	
	if(fd_flag & O_APPEND)
		printf("stdout: append.\n");
	if(fd_flag & O_NONBLOCK)
		printf("stdout: nonblock.\n");
	if(fd_flag & O_SYNC)
		printf("stdout: sync. \n");
	
	exit(0);
}
