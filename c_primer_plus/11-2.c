#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUF 256

char line[BUF] = {0};

int readFirstWord(char * to, char *from);

int main(void)
{
	char *str = NULL;
	int size = 0;
	char word[40];
	
	printf("Enter some text please,I will read the first word. \n");
	str = fgets(line, BUF, stdin);
	if(str == NULL)
	{
		printf("fgets err\n");
		return 1;
	}
	size = readFirstWord(word, line);
	if(size == -1)
	{
		printf("readWord failed\n");
		return 1;
	}
	printf("The first word is : %s, size = %d\n", word, size);
	return 0;
}

int readFirstWord(char * to, char *from)
{
	int count = 0;
	
	if(from == NULL || to == NULL)
	{
		printf("param err\n");
		return -1;
	}
	
	//跳过行首的空格
	while(isspace(*from))
	{
		from++;
	}
	
	while(!isspace(*from))
	{
		*to++ = *from++;
		count++;
	}
	*to = '\0';
	
	return count;
}
