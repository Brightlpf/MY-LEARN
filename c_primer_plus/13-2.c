#include <stdio.h>
#include <stdlib.h>
#define BUF 1024

char buffer[BUF];

int main(int argc, char * argv[])
{
	FILE * fp_src = NULL;
	FILE * fp_dst = NULL;
	size_t n_byte = 0;
	
	if(argc != 3)
	{
		printf("Useage: %s file1 file2\n", argv[0]);
		exit(1);
	}
	
	fp_src = fopen(argv[1], "rb");
	if(NULL == fp_src)
	{
		printf("open %s failed.\n", argv[1]);
		exit(1);
	}
	fp_dst = fopen(argv[2], "wb+");
	if(NULL == fp_src)
	{
		printf("open file2 failed.\n");
		exit(1);
	}
	/*
	while((n_byte = fread(buffer, sizeof(char), BUF, fp_src)) != 0) 
	{
		fwrite(buffer, sizeof(char), BUF, fp_dst);
		if(n_byte == 0)
		{
			printf("read file failed.\n");
			exit(1);
		}
	}
	*/
	while((n_byte = getc(fp_src)) != EOF)
	{
		putc(n_byte, fp_dst);
	}
	fclose(fp_src);
	fclose(fp_dst);
	
	return 0;
}
