#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 20
#define BUF 256

typedef struct 
{
	char first_name[N];
	char second_name[N];
	char last_name[N];
}NAME;

typedef struct 
{
	char social_no[N];
	NAME name;
}Social_info;

void display(Social_info s_info)
{	
	char secname[N];
	int i;
	
	strcpy(secname, s_info.name.second_name);
	for(i = 0; secname[i] != '\0'; i++)
	{
		secname[i] = toupper(s_info.name.second_name[i]);
	}
	if(strncmp(secname, "NO", 2) == 0)
	{
		printf("name: %s  %s\n", s_info.name.first_name,  s_info.name.last_name);
	}
	else
	{
		printf("name: %s %c. %s\n", s_info.name.first_name, s_info.name.second_name[0], s_info.name.last_name);
	}
	
	printf("Social security number: %s\n", s_info.social_no);
}

int main(void)
{
	Social_info s_info;
	
	while(1)
	{
		printf("first_name: \n");
		scanf("%s", s_info.name.first_name);
		printf("second_name(if don't have it, enter 'no'): \n");
		scanf("%s", s_info.name.second_name);
		printf("last_name: \n");
		scanf("%s", s_info.name.last_name);
		
		printf("social security number: \n");
		scanf("%s", s_info.social_no);
		puts("You input info:");
		display(s_info);
	}
}