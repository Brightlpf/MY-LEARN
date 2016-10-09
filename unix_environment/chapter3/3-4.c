#include <apue.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		err_quit("USAGE: ./a.out fileds");
	}
	
	int val;
	
	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		err_quit("fcntl %d failed", argv[1]);
	
	switch(val & O_ACCMODE)
	{
		case O_RDONLY:
			printf(" read only");
			break;
		case O_WRONLY:
			printf(" write only");
			break;
		case O_RDWR:
			printf("read write");
			break;
		default:
			err_dump("don't recgnize mode\n");
			break;
	}
	
	if(val & O_APPEND)
	{
		printf(", append");
	}
	
	if(val & O_NONBLOCK)
		printf(", nonblcok");
	
	#ifdef O_SYNC
		if(val & O_SYNC)
			printf(", sync");
	#endif
	
	#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
		if(val & O_FSYNC)
			printf(", synchronous writes");
	#endif
		putchar('\n');
	exit(0);
}
