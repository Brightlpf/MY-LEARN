#include <stdio.h>
#include <stdlib.h>

int is_Bigendian(void);
int main()
{
	if (is_Bigendian())
	{
		printf("BIG ENDIAN\n");
	}
	else
	{
		printf("Little ENDIAN\n");
	}
	exit(0);
}

int is_Bigendian(void)
{
	int data = 0x11223344;
	char * pd;
	
	pd = (char *)&data;
	printf("pd[0] = 0x%x, pd[1] = 0x%x, pd[2] = 0x%x, pd[3] = 0x%x\n", pd[0], pd[1], pd[2], pd[3]);
	if((pd[0] == 0x44) && (pd[1] == 0x33) &&(pd[2] == 0x22) &&(pd[3] == 0x11))
	{
		return 0;
	}
	return 1;
}
