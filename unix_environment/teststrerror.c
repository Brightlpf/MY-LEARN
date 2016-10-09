#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char ** argv)
{
	int fd;
	
	printf("Test strerror......\n\n");
	fd = open("noexist", O_RDONLY);
	if(fd < 0)
	{
		printf("file \"notexist\": %s\n", strerror(errno));
	}
	fd = open("/etc/passwd", O_WRONLY);
	
	if(fd < 0)
		printf("open \"/etc/passwd\": %s\n", strerror(errno));
	
	printf("Test perror......\n\n");
	errno = EINVAL;
	perror("EINVAL");
	
	_exit(0);
}
