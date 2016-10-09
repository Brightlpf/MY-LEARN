#include <apue.h>
#include <pwd.h>

static void my_alarm(int signo);

int main(void)
{
	struct passwd *ptr;
	unsigned int timeleft;
	int count = 0;

	signal(SIGALRM, my_alarm);
	timeleft = alarm(1);
	printf("[main]timeleft = %d\n", timeleft);

	while(1)
	{
		if((ptr = getpwnam("lpf")) == NULL)
		{
			err_quit("getpwname error");
		}
		if(strcmp("lpf", ptr->pw_name)!=0)
		{
			printf("return value corrupted! pw_name = %s\n", ptr->pw_name);
			exit(0);
		}
	}

exit(0);
}

static void my_alarm(int signo)
{
struct passwd *rootptr = NULL;
sigset_t sigset;

printf("in signal handler\n");

if(sigprocmask(0, NULL, &sigset) < 0)
{
	err_sys("sigprocmask error");
}
else
{
	if(sigismember(&sigset, SIGALRM))
		printf("SIGALRM\n");
	else
		printf("NOT MASK SIGALRM\n");
}

	if(signal(SIGALRM, my_alarm) == SIG_ERR)
	{
	perror("signal error");
	}
/*
if((rootptr = getpwnam("root")) == NULL)
{
err_sys("getpwname root error");
}

printf("[my_alarm] root name = %s\n", rootptr->pw_name);
*/
alarm(1);
}