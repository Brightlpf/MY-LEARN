#include <apue.h>
#include <pwd.h>

static void my_alarm(int signo);

int main(void)
{
	struct passwd *ptr;
	int count = 0;
	
	signal(SIGALRM, my_alarm);
	alarm(1);
	
	while(1)
	{
		if((ptr = getpwnam("lpf")) == NULL)
		{
			err_quit("getpwname error");
		}
		//printf("[main]ptr = %s\n", ptr->pw_name);
		if(strcmp("lpf", ptr->pw_name)!=0)
		{
			printf("return value corrupted! pw_name = %s\n", ptr->pw_name);
			exit(0);
		}
		//printf("[main]count = %d\n", count++);	
		//sleep(1);sleep()可能由alarm()实现，共用定时器，和alarm共同使用is a bad idea
	}
	
	exit(0);
}

static void my_alarm(int signo)
{
	struct passwd *rootptr;
	rootptr = NULL;
	
	printf("in signal handler\n");
	
	if(signal(SIGALRM, my_alarm) == SIG_ERR)
	{
		perror("signal error");
	}
	/*
	if((rootptr = getpwnam("root")) == NULL)
	{
		err_sys("getpwname root error");
	}
	
	
	*/
	alarm(1);
}
