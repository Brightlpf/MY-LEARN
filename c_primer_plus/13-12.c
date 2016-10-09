#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int data[20][31];
char image[20][31];
char sign[11] = " .':~*=&#@";

int main(void)
{
	
	FILE * fp;
	int n;
	int count = 0;
	int i, j;
	char  str[10];
	
	//创建文件
	if((fp = fopen("img.data", "w+")) == NULL)
	{
		fprintf(stderr, "creat file img.jpg failed.\n");
		exit(EXIT_FAILURE);
	}
	//往文件中写入数据
	/*  write char
	srand(time(NULL));
	while(count < 20 * 30)
	{
		n = rand() % 10;
		sprintf(str, "%d", n);
		if(putc(str[0], fp) == EOF)
		{
			fprintf(stderr, "write file failed\n");
			exit(EXIT_FAILURE);
		}
		count++;
		if(count % 30 == 0)
		{
			if(putc((int)'\n', fp) == EOF)
			{
				fprintf(stderr, "write file failed\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if(putc((int)' ', fp) == EOF)
			{
				fprintf(stderr, "write file failed\n");
				exit(EXIT_FAILURE);
			}
		}	
	}
	*/
	srand(time(NULL));
	while(count < 20 * 30)
	{
		n = rand() % 10;
		if(fprintf(fp,"%d", n) < 0)
		{
			fprintf(stderr, "write file failed\n");
			exit(EXIT_FAILURE);
		}
		count++;
		if(count % 30 == 0)
		{
			if(putc((int)'\n', fp) == EOF)
			{
				fprintf(stderr, "write file failed\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if(putc((int)' ', fp) == EOF)
			{
				fprintf(stderr, "write file failed\n");
				exit(EXIT_FAILURE);
			}
		}	
	}
	//cp 文件中的数据到二维数组中
	/*
	count = 0;
	for(i = 0; i < 20; i++)
		for(j = 0; j < 30; j++)
		if(fscanf(fp, "%d", &data[i][j]) == EOF)
		{
			fprintf(stderr, "read data file failed\n");
			exit(EXIT_FAILURE);
		}
	*/
	/*
	if(fclose(fp) == EOF)
	{
		fprintf(stderr, "close file failed\n");
		exit(EXIT_FAILURE);
	}
	if((fp = fopen("img.data", "r+")) == NULL)
	{
		fprintf(stderr, "read file img.data failed.\n");
		exit(EXIT_FAILURE);
	}
	*/
	
	fseek(fp, 0L, SEEK_SET);
	//如何把从文件中读取的数据存储到二维数组中？
	for(i = 0; i < 20; i++)
		for(j = 0; j < 30; j++)
		fscanf(fp, "%d", &data[i][j]);
	if(ferror(fp))	
	{
		fprintf(stderr, "read data file failed\n");
		exit(EXIT_FAILURE);
	}
	/*
	i = 0;
	j = 0;
	while((n = getc(fp)) != EOF)
	{
		if(isspace(n))
			continue;
		if( i < 20 && j < 31)
		{
			if( j == 30)
			{
				data[i][j] = '\0';
				i++;
				j = 0;
			}
			else
			{
				data[i][j] = n;
				j++;
			}	
		}
		else
		{
			break;
		}
	}
	*/
	//关闭文件
	if(fclose(fp) == EOF)
	{
		fprintf(stderr, "close file failed\n");
		exit(EXIT_FAILURE);
	}
	//将数组中数字代表的符号打印出来
	count =0;
	for(i = 0; i < 20; i++)
		for(j = 0; j < 30; j++)
		{
			//if( putc(sign[atoi((char *)&data[i][j])], stdout) == EOF)
			if( putc(sign[data[i][j]], stdout) == EOF)
			{
				fprintf(stderr, "show image failed\n");
				exit(EXIT_FAILURE);
			}
			count++;
			if(count % 30 == 0)
			{
				if(putc((int)'\n', stdout) == EOF)
				{
					fprintf(stderr, "write file failed\n");
					exit(EXIT_FAILURE);
				}
			}
		}
		
	exit(EXIT_SUCCESS);
}
