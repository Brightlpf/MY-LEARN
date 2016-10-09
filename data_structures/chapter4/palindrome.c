#include "Stack.h"
//判断字符串是否是回文
#define MAX 100

int ispld(Stack * st, const char * str);

int main(void)
{
	Stack * st;
	char data[MAX];
	
	st = initStack();
	while(1)
	{
		printf("Please enter a string.\n");
		fgets(data, MAX -1 , stdin);
		printf("input: %s\n", data);
		if(ispld(st, data))
			printf("is palindrome.\n");
		else
			printf("isn't palindrome.\n");
	}

	destoryStack(st);
	return 0;
}

int ispld(Stack * st, const char * str)
{
	const char * pst = str;
	Element e;
	
	while(*str && *str != '\n')
	{
		e.ch = *str++;
		PUSH(st, e);
		printf("push: %c\n", e.ch);
	}
		
	while(!isEmpty(st))
	{
		POP(st, &e);
		printf("[pop: %c, *pst = %c\n", e.ch, *pst);
		if(e.ch != *pst++)
		{
			while(!isEmpty(st))
				POP(st, &e);
			return 0;
		}	
	}
	return 1;
}
