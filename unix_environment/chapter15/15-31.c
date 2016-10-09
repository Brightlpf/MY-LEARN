#include <apue.h>
#include <sys/shm.h>

#define ARRAY_SIZE 4000
#define MALLOC_SIZE 100000
#define SHM_SIZE 100000
#define SHM_MODE 0600

char bss[ARRAY_SIZE];

int main(void)
{
	char arr[ARRAY_SIZE];
	char *ptr;
	int shmid;
	char *pshm;
	
	if((ptr = (char *)malloc(sizeof(char) *MALLOC_SIZE)) == NULL)
	{
		printf("malloc error\n");
		exit(1);
	}
	//获取shmid
	shmid = shmget(IPC_PRIVATE, SHM_SIZE,  SHM_MODE);
	if(shmid < 0)
	{
		perror("shmgetid");
		exit(1);
	}
	//连接到进程
	if((pshm = shmat(shmid, 0, 0)) < 0)
	{
		perror("shmat error");
		exit(1);
	}
	//打印各种变量的地址
	printf("stack : from %p ~ %p\n", arr, &arr[ARRAY_SIZE]);
	printf("heap  : from %p ~ %p\n", ptr, &ptr[MALLOC_SIZE]);
	printf("bss   : from %p ~ %p\n", bss, &bss[ARRAY_SIZE]);
	printf("shm   : from %p ~ %p\n", pshm, &pshm[SHM_SIZE]);
	
	//与进程分离
	if(shmdt(pshm) < 0)
		perror("shmdt");
	
	shmctl(shmid, IPC_RMID, 0);
	exit(0);
}
