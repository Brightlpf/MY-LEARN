#include <stdio.h>

int main(void)
{
	int space, lines, others;
	char ch;
	
	printf("statistics space lines others\n");
	printf("Please enter some text end with 'end'.\n");
	
	space = 0;
	lines = 0;
	others = 0;
	while((ch = getchar())!='#')
	{
		if(ch == '\n')	
		{
			lines++;		
		}	
		else if(ch ==' ')
		{
			space++;
		}	
		else
		{
			others++;
		}
		
	}
	
	printf("space is %d, lines is %d, other is %d\n", space, lines, others);
	
	return 0;
}
