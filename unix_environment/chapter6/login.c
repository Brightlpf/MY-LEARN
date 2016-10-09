#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>

int main(void)
{
	char user[20];
	char passwd[20];
	struct spwd *ptr;
	
	printf("user: ");
	scanf("%s", user);
	printf("passwd: ");
	scanf("%s", passwd);
	ptr = (struct spwd *)malloc(sizeof(struct spwd));
	if(NULL == ptr)
	{
		printf("get memory failed.\n");
		exit(1);
	}
	setspent();
	while((ptr = getspent())!= NULL)
		if(strcmp(user, ptr->sp_namp) == 0)
			break;
	if(NULL == ptr)
	{
		printf("no user\n");
		exit(1);
	}
	printf("ptr->sp_pwdp = %s\n", ptr->sp_pwdp);
	endspent();
	exit(0);
}
