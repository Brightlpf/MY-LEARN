#include <apue.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int newfd;
	off_t currpos;
	int nbytes;
	char str[BUFSIZ];
	
	int fd2;
	int save_fd;
	
	if((fd = open("creatfile.c", O_RDONLY)) < 0)
	{
		err_quit("open creatfile.c err");
	}
	currpos = lseek(fd, 30, SEEK_SET);
	newfd = dup(fd);
	if((nbytes = read(newfd, str, BUFSIZ)) > 0)
	{
		fd2 = open("file_cpy.c", O_WRONLY | O_CREAT, 0661);
		if(fd2 < 0)
		{
			err_quit("open file_cpy.c failed");
		}
		write(fd2, str, nbytes);
		save_fd = dup(STDOUT_FILENO);
		printf("save_fd = %d\n", save_fd);
		
		dup2(fd2, STDOUT_FILENO);
		printf("Hello world!\n");
		dup2(save_fd, STDOUT_FILENO);
		printf("STDOUT_FILENO = %d. ", STDOUT_FILENO);
		printf("How are you!\n");
	}
	exit(0);
}
