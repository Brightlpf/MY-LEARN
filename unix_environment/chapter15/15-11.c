#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define LINEMAX 1024

int main(int argc, char * argv[])
{
	FILE * fp, * fpipe;
	char buf[LINEMAX];
	int len;

	if(argc != 2)
	{
		printf("Usage: %s [file]", argv[0]);
		exit(1);
	}
	
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen error");
		exit(1);
	}
	fpipe = popen("/bin/more", "w");
	if(fpipe == NULL)
	{	
		perror("fopen error");
		exit(1);
	}
	
	while(fgets(buf, LINEMAX, fp) != NULL)
	{
		//len = strlen(buf);
		fputs(buf, fpipe);
	}
	fclose(fp);
	pclose(fpipe);
	exit(0);
}
