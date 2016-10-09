#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int lower = 0, upper = 0;
	char ch;
	
	while((ch = getchar()) != EOF)
	{
		if(isupper(ch)) 
		{
			upper++;
		}
		if(islower(ch))
		{
			lower++;
		}
	}
	printf("upper = %d, lower = %d\n", upper, lower);
	return 0;	
}
