#include <apue.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd;
	char str[100];
	
	//创建文件，并输入任意内容供测试
	fd = open("test3.6.file", O_WRONLY | O_CREAT, 0660);
	if(fd < 0)
		err_quit("open test3.6.file failed");
	
	write(fd, "Hello world!\n", 13);
	write(fd, "1234567890\n", 11);
	write(fd, "abcdefg\n", 8);
	close(fd);
	
	//测试读取从 文件开头，中间，结尾
	fd = open("test3.6.file", O_RDWR | O_APPEND);
	if(fd < 0)
		err_quit("open test3.6.file rdwr failed");
	printf("read from start: ");
	//fflush(stdout);
	lseek(fd, 0, SEEK_SET);
	if( read(fd, str, 13) > 0)
		write(STDOUT_FILENO, str, strlen(str));
	
	printf("read from MID: ");
	fflush(stdout);
	lseek(fd, 14, SEEK_SET);
	if( read(fd, str, 11) > 0)
		write(STDOUT_FILENO, str, strlen(str));
	
	printf("read from END: ");
	fflush(stdout);
	lseek(fd, -8, SEEK_END);
	if( read(fd, str, 8) > 0)
		write(STDOUT_FILENO, str, strlen(str));
	
	//测试往文件中写
	lseek(fd, 0, SEEK_SET);
	write(fd, "##########", 10);
	
	lseek(fd, 20, SEEK_SET);
	write(fd, "@@@@@@@@@@", 10);
	
	lseek(fd, 0, SEEK_END);
	write(fd, "**********", 10);
	
	exit(0);
}
