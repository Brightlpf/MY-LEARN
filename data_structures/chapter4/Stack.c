#include "Stack.h"
#define CAP 100

Stack * initStack(void)
{
	Stack * pst;
	pst = (Stack *)malloc(sizeof(Stack));
	if(NULL == pst)
	{
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
	{
		addSpace(st);
	}
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

int getTop(Stack * st, Element *e)
{
	if(NULL == st || NULL == e)
	{
		printf("getTop error\n");
		return 0;
	}
	*e = st->pelem[st->top];
	return 1;
}
