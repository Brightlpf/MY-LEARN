#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <syslog.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

void mydaemon(const char *name);
void printtime(void);
int main(int argc, char * argv[])
{
	char *plogin;
	
	if(argc > 2 || argc < 1)
	{
		printf("parameter error\n");
		return 0;
	}
	mydaemon(argv[0]);
	plogin = getlogin();
	if(NULL == NULL)
	{
		syslog(LOG_ERR, "getlogin is NULL");
	}
	else
		syslog(LOG_ERR, "getlogjin: %s", plogin);
	
	while(1)
	{
		printtime();
		sleep(60);
	}
	
	return 0;
}

void mydaemon(const char *name)
{
	pid_t pid;
	int fd0, fd1, fd2;
	
	umask(0);
	if((pid = fork()) < 0)
	{
		printf("fork1 error");
		exit(1);
	}
	else if(pid > 0)
	{
		exit(0);
	}
	setsid();
	if((pid = fork()) < 0)
	{
		exit(1);
	}
	else if(pid > 0)
	{
		exit(0);
	}
	
	if(chdir("/") < 0)
	{
		printf("can't cd '/'\n");
	}
	close(0);
	close(1);
	close(2);
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);
	
	openlog(name, LOG_PID, LOG_LPR);
	if(fd0!= 0 || fd1 != 1 ||fd2 != 2)
	{
		syslog(LOG_ERR, "unexcept file description %d %d %d", fd0, fd1, fd2);
		exit(1);
	}
}

void printtime(void)
{
	time_t t;
	struct tm * local_t;
	
	time(&t);
	local_t = localtime(&t);
	syslog(LOG_INFO, "now time is %d:%d:%d\n", local_t->tm_hour, local_t->tm_min, local_t->tm_sec);
	
}
