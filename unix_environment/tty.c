#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char input[1024];
	
	fd = open("/dev/tty", O_RDWR);
	read(fd, input, 12);
	write(fd, "hello world!", 12);
	printf("Bye!\n");
}
