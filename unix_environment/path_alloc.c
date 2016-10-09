#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

#ifdef PATH_MAX 
static long path_max = PATH_MAX;
#else
static long path_max = 0;
#endif

static long 	posix_version = 0;
static long 	xsi_version = 0;

#define PATH_MAX_GUESS 1024

char *path_alloc(int *psize)
{
	int ret;
	int path_size;
	char * ptr;
	
	#ifdef _SC_VERSION
	posix_version = sysconf(_SC_VERSION);
	#endif
	#ifdef _SC_XOPEN_VERSION
	xsi_version = sysconf(_SC_XOPEN_VERSION);
	#endif
	
	if(path_max == 0)
	{
		errno = 0;
		ret = pathconf("/", _PC_PATH_MAX);
		if(ret < 0)
		{
			if(errno!=0)
			{
				printf("pathconf error\n");
				exit(1);
			}
			else{
				printf("no limit\n");
				path_max = PATH_MAX_GUESS;
			}
		}
		else{
			path_max = ret + 1; 
		}
	}
	
	if((posix_version < 200112L)&&(xsi_version < 4))
	{
		path_size = path_max + 1;
	}
	else{
		path_size = path_max;
	}
	if((ptr = malloc(sizeof(char)* path_size)) == NULL)
	{
		printf("malloc error\n");
		exit(1);
	}
	if(NULL != psize)
	{
		*psize = path_size;
	}
	return ptr;
}

int main(void)
{
	char *ptr;
	int size;
	
	printf("Test path_alloc......\n");
	ptr = path_alloc(&size);
	if(ptr == NULL)
	{
		exit(1);
	}
	printf("path_max = %d\n", size);
	printf("enter the dir: ");
	scanf("%s", ptr);
	if(chdir(ptr) == -1)
	{
		perror(ptr);
		return 1;
	}
	printf("cd %s success\n", ptr);
	open("temfile.pathalloc", O_RDONLY | O_CREAT);
	return 0;
}
