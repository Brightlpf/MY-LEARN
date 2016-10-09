#include "Stack.h"

#define MAX  100

int isPopSeq(Stack * pst, int input[], int output[], int n);

int main(void)
{
	int input[MAX] = {1, 2, 3, 4, 5};
	//int output[MAX] = {4, 5, 3, 2, 1};
	int output[MAX] = {4, 3, 5, 1, 2};
	Stack * pst;
	
	pst = initStack();
	
	if(isPopSeq(pst, input, output, 5))
	{
		printf("It's Pop sequence.\n");
	}
	else
		printf("It's not Pop sequence.\n");
	
	return 0;
}

int isPopSeq(Stack * pst, int input[], int output[], int n)
{
	Element e;
	int in = 0;
	int out = 0;
	
	if(n > MAX)
	{
		fprintf(stderr, "error.\n");
		exit(1);
	}

	e.elem = input[in++];
	PUSH(pst, e);
	printf("PUSH %d\n", e.elem);

	while(!isEmpty(pst))
	{
		getTop(pst, &e);
		if(e.elem != output[out])
		{
			if(in < n)
			{
				e.elem = input[in++];
				PUSH(pst, e);
				printf("PUSH %d\n", e.elem);
			}
			else
			{
				return 0;
			}
		}
		else
		{
			POP(pst, &e);
			printf("Pop %d\n", e.elem);
			out++;
		}
	}
	
	return 1;
}
