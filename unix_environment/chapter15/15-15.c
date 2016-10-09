#include <apue.h>
#include <sys/wait.h>

int main(void)
{
	FILE *fpin;
	char line[MAXLINE];
	
	if((fpin = popen("./myuclc", "r")) ==NULL)
		err_sys("popen error");
	
	while(1)
	{		
		fputs("promt> ", stdout);
		fflush(stdout);
		
		if(fgets(line, MAXLINE, fpin) == NULL)
			break;
		if(fputs(line, stdout) == EOF)
			err_sys("fputs error to pipe");
	}
	if(pclose(fpin) == -1)
		err_sys("pclose error");
	putchar('\n');
	exit(0);
}
