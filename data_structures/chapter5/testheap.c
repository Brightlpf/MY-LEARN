#include "heap.h"
#include <stdlib.h>
#include <time.h>


int main(void)
{
	Heap hp;
	int i;
	srand(time(NULL));
	Element e;
	
	initHeap(&hp);
	for(i = 0; i < 10; i++)
	{
		e.key = rand()%100;
		push(&hp, e);
	}
	printf("show heap: \n");
	showHeap(&hp);
	/*
	for(i = 1; i <= 10; i++)
	{
		e = pop(&hp);
		printf("pop %d: \n", e.key);
		showHeap(&hp);
	}
*/
	printf("set 1 to 100: \n");
	setvalue(&hp, 1, 100);
	showHeap(&hp);
	
	return 0;
}

