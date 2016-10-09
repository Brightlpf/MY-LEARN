#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 1024

//略去 . .. 目录

int skip_ivlddir(const char *path);
long mydu(const char *path);


int skip_ivlddir(const char *path)
{
	char *pos;

	pos = strrchr(path, '/');
	if(NULL == pos)
	{
		printf("strrchr error\n");
		exit(1);
	}
	if((strcmp(pos, "/.") == 0) || (strcmp(pos, "/..") == 0))
	{
		return 1;
	}
	
	return 0;
	
}

long mydu(const char *path)
{
	char * pos;
	glob_t glob_buf;
	int i;
	struct stat stat_buf;
	int ret;
	static char str[BUFSIZE] = "";
	
	if(NULL == path)
	{
		printf("parameter error\n");
		exit(1);
	}
	lstat(path, &stat_buf);
	if(S_ISDIR(stat_buf.st_mode))
	{
		//非隐藏文件
		snprintf(str, BUFSIZE, "%s/*", path);
		glob(str, 0, NULL, &glob_buf);
		
		//隐藏文件
		snprintf(str, BUFSIZE, "%s/.*", path);
		glob(str, GLOB_APPEND, NULL, &glob_buf);
		
		ret = stat_buf.st_blocks;
		for(i = 0; i < glob_buf.gl_pathc; i++)
		{
			pos = glob_buf.gl_pathv[i];
			if(!skip_ivlddir(pos))
			{
				ret += mydu(glob_buf.gl_pathv[i]);
			}
		}
		globfree(&glob_buf);
	}
	else
	{
		ret = stat_buf.st_blocks;
	}
	
	return ret;
}

int main(int argc, char **argv)
{
	printf("%d\n", mydu(argv[1]) / 2);
	
	return 0;
}
