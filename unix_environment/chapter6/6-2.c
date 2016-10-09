#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>
/*
struct passwd * getpwnam(const char *name)
{
	struct passwd *ptr;
	
	setpwent();
	while((ptr = getpwent()) != NULL)
		if(strcmp(name, ptr->pw_name) == 0)
			break;
	endpwent();
	return ptr;
}
*/
int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s [username]\n", argv[0]);
		exit(1);
	}
	
	struct passwd * pw;
	
	pw = (struct passwd *)malloc(sizeof(struct passwd));
	if(NULL == pw)
	{
		printf("get memory failed.\n");
		exit(1);
	}
	
	pw = getpwnam(argv[1]);
	
	printf("user = %s, uid = %d, gid = %d, home = %s\n", pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir);
}
