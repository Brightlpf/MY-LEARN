// test mydup2 hello world
= 4
// test mydup2 hello world
ONEM 1*1024*1024*1024UL
int main(void)
{
	int fd, fd2;
	off_t currpos;
	char str[100];
	int nbyte;
	
	if((fd = open("file_100M", O_RDWR|O_CREAT, 0660)) < 0)
	{
		fprintf(stderr, "open file1 failed.\n");
		exit(1);
	}
	if((fd2 = open("file_cpy", O_WRONLY|O_CREAT, 0660)) < 0)
	{
		fprintf(stderr, "open file2 failed.\n");
		exit(1);
	}
	if(write(fd, "hello world!", 12) != 12)
	{
		fprintf(stderr, "write file failed.\n");
		exit(1);
	}
	if( currpos = lseek(fd, ONEM, SEEK_SET) == -1)
	{
		fprintf(stderr, "lseek failed.\n");
		exit(1);
	}
	if(write(fd, "hello world!", 12) != 12)
	{
		fprintf(stderr, "write file failed.\n");
		exit(1);
	}
	
	if( currpos = lseek(fd, 5, SEEK_SET) == -1)
	{
		fprintf(stderr, "lseek failed.\n");
		exit(1);
	}
	if((nbyte = read(fd, str, 20)) > 0)
	{
		if(write(fd2, str, nbyte) != nbyte)
		{
			fprintf(stderr, "write file_cpy failed.\n");
			exit(1);
		}
	}
	close(fd2);
	close(fd);
	
	exit(0);
}
Hello world!
