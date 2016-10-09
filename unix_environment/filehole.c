#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
        int fd;

        fd = open("holefile", O_RDWR | O_CREAT, 0664);
        if(fd == -1)
                perror("holefile");

        lseek(fd, 1024*1024*2UL, SEEK_SET);
        write(fd, "", 1);
        close(fd);
        return (0);
}
