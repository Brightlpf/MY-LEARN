#include <apue.h>

static void charatatime(char * str);

int main(void)
{
	pid_t pid;
	
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
	{
		charatatime("output from child.\n");
		exit(0);
	}
	else
	{
		charatatime("output from father\n");
		exit(0);
	}
}

static void charatatime(char *str)
{
	char *ptr;
	char c;
	
	setbuf(stdout, NULL);
	for(ptr = str; (c= *ptr++)!= 0; )
		putc(c, stdout);
}
