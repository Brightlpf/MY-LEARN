#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <shadow.h>
#include <string.h>
#include <crypt.h>

int login(void);

int main(void)
{
	int ret;
	
	ret = login();
	if(ret)
	{
		printf("login success!\n$ ");
	}
	else
	{
		printf("login fail!\n");
	}
	return 0;
}

int login(void)
{
	char username[50];
	char *p;
	struct spwd *sppw;
	int ret;
	
	printf("user: ");
	scanf("%s", username);
	p = getpass("passwd: ");
	
	sppw = getspnam(username);
	if(NULL == sppw)
	{
		printf("getpwnam error\n");
		return 0;
	}
	if(strcmp(crypt(p, sppw->sp_pwdp), sppw->sp_pwdp) == 0)
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}
	return ret;
}
