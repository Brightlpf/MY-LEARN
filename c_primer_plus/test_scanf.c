#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char str[256];
	while(1)
	{
		if(scanf("%s", &str) == 1)
		{
			printf(str);
			printf("\n");
		}
		else
		{
			printf("scanf error!\n");
		}
		sleep(10);
	}
	return 0;
}
