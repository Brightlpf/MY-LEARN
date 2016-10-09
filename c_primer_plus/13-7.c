#include <stdio.h>
#include <stdlib.h>
#define LINE 256

char buffer[LINE];

int main(int argc, char *argv[])
{
	FILE *fp1;
	FILE *fp2;
	char * p1;
	char * p2;
	int ret1, ret2;
	
	if(argc != 3)
	{
		printf("Useage: %s file1 file2\n", argv[0]);
		exit(1);
	}
	
	if((fp1 = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "open %s failed\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if((fp2 = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "open %s failed\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while(1)
	{
		if((p1 = fgets(buffer, LINE, fp1)) != NULL)
		{
			fputs(buffer, stdout);
		}
		if((p2 = fgets(buffer, LINE, fp2)) != NULL)
		{
			fputs(buffer, stdout);
		}
		if(p1 == NULL && p2 == NULL)
			break;
	}
	ret1 = fclose(fp1);
	ret2 = fclose(fp2);
	if(ret1 !=0 || ret2 !=0)
	{
		fprintf(stderr, "close faile failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
