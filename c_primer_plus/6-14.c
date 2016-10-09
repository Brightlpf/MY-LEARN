#include <stdio.h>
#include <string.h>

int main(void)
{
	char lines[256] = {'\0'};
	char ch;
	int i = 0;
	
	printf("Please enter some text:\n");
	scanf("%c", &ch);
	while(ch != '\n')
	{
		lines[i++] = ch;
		scanf("%c", &ch);
	}
	lines[i] = '\0';
	
	printf("reverse: ");
	for(i = strlen(lines) - 1; i >=0; i--)
	{
		printf("%c", lines[i]);
	}
	printf("\n");
}
