#include <apue.h>
#include <sys/socket.h>

int main(void)
{
	int sockfd = 0;
	struct stat sbuf;
	
	if((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
	{
		printf("socket error.\n");
		exit(1);
	}
	
	memset(&sbuf, 0, sizeof(sbuf));
	fstat(sockfd, &sbuf);
	
	printf("type = %d", sbuf.st_mode);
	if(S_ISSOCK(sbuf.st_mode))
		printf("\t (SOCKET)\n");
	else
		printf("\n");
	printf("inode number = %d\n", sbuf.st_ino);
	printf("uid = %d\n", sbuf.st_uid);
	printf("gid = %d\n", sbuf.st_gid);
	
	return 0;
}
