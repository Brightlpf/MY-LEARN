#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define CAP	10

typedef struct Element {
	int key;
	/*other*/
} Element;

typedef struct Stack {
	Element * pelem;
	int top;
	int capacity;
}Stack;

Stack * initStack(void);
int isEmpty(const Stack * st);
int isFull(const Stack * st);
int addSpace(Stack * st);
int PUSH(Stack * st, Element e);
int POP(Stack * st, Element * e);
int destoryStack(Stack * st);

int main()
{
	Stack * st;
	Element temp;
	int i;
	
	st = initStack();
	if(NULL == st)
		return 1;
	
	for(i = 0; i < CAP+1; i++)
	{
		temp.key = 2 * i + 1;
		if(isFull(st))
		{
			printf("Stack is Full.\n");
			break;
		}
		PUSH(st, temp);
		printf("push : %d\t", temp.key);
		if(i % 5 == 4)
			printf("\n");
	}
	
	for(i = 0; i < CAP + 1; i++)
	{
		if(isEmpty(st))
		{
			printf("Stack is empty.\n");
			break;
		}
		POP(st, &temp);
		printf("pop: %d\t", temp.key);
		if(i % 5 == 4)
			printf("\n");
	}
	//dynamic add capicity
	for(i = 0; i < 2 * CAP + 1; i++)
	{
		temp.key = 2 * i + 1;
		if(isFull(st))
		{
			printf("\nStack is Full, dynamic add space.\n");
			if(!addSpace(st))
			{
				printf("add space failed.\n");
				return 1;
			}
		}
		PUSH(st, temp);
		printf("push : %d\t", temp.key);
		if(i % 5 == 4)
			printf("\n");
	}
	printf("\n");
	
	while(!isEmpty(st))
	{
		static int count = 0;
		POP(st, &temp);
		printf("pop: %d\t", temp.key);
		if(count++ % 5 == 4)
			printf("\n");
	}
	destoryStack(st);
	
	return 0;
}

Stack * initStack(void)
{
	Stack * pst;
	pst = (Stack *)malloc(sizeof(Stack));
	if(NULL == pst)
	{
		fprintf(stderr, "initStack failed.\n");
		return NULL;
	}
	pst->top = -1;
	pst->capacity = CAP;
	pst->pelem = (Element *)malloc(CAP * sizeof(Element));
	if(NULL == pst->pelem)
	{
		fprintf(stderr, "initStack failed.\n");
		return NULL;
	}
	
	return pst;
}

int isEmpty(const Stack * st)
{
	if (st->top == -1)
		return 1;
	return 0;
}

int isFull(const Stack * st)
{
	if(st->top == st->capacity -1)
		return 1;
	return 0;
}

int addSpace(Stack * st)
{
	if(NULL == st)
	{
		printf("addSpace error.\n");
		return 0;
	}
	st->pelem = (Element *)realloc(st->pelem, 2 * st->capacity * sizeof(Element));
	if(NULL == st->pelem)
	{
		return 0;
	}
	st->capacity = 2 * st->capacity;
	return 1;
}

int PUSH(Stack * st, Element e)
{
	if(++st->top == st->capacity)
		return 0;
	st->pelem[st->top] = e;
	return 1;
}

int POP(Stack * st, Element * e)
{
	if(st->top == -1)
		return 0;
	memcpy(e, &st->pelem[st->top--], sizeof(Element));
	return 1;
}

int destoryStack(Stack * st)
{
	if(NULL == st)
		return 1;
	free(st->pelem);
	free(st);
	return 1;
}
