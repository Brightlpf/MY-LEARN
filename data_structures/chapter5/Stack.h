#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Element {
	void * elem;
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
int getTop(Stack * st, Element *e);
