#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bintoi(char * bin);
char * itobin(int n, char *ps);

int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		printf("err paramer\n");
		return 1;
	}
	
	int opt1, opt2;
	char str[8 * sizeof(int) + 1];
	
	opt1 = bintoi(argv[1]);
	opt2 = bintoi(argv[2]);
	printf("opt1 = %d, opt2 = %d\n", opt1, opt2);
	printf("~opt1 = %d, ~opt2 = %d\n\n", ~opt1, ~opt2);
	printf("%d & %d = %d\n", opt1, opt2, opt1 & opt2 );
	
	printf("(~%s) = %s\n", argv[1], itobin(~opt1, str));
	printf("(~%s) = %s\n", argv[2], itobin(~opt2, str));
	printf("(%s)|(%s) = %s\n", argv[1], argv[2], itobin(opt1 | opt2, str));
	printf("(%s)&(%s) = %s\n", argv[1], argv[2], itobin(opt1 & opt2, str));
	printf("(%s)^(%s) = %s\n", argv[1], argv[2], itobin(opt1 ^ opt2, str));
	return 0;
}

int bintoi(char *bin)
{
	int sum = 0;
	while(*bin)
	{
		sum = sum * 2 + (*bin++ - '0');
	}
	return sum;
}

char * itobin(int n, char *ps)
{
	int i;
	static int size = 8 * sizeof(int);
	
	for(i = size - 1; i >= 0; i--)
	{
		ps[i] = (n & 01) + '0';
		n >>= 1;
	}
	ps[size] = '\0';
	
	return ps;
}
