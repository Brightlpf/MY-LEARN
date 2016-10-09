#include "heap.h"
#include <stdlib.h>


void push(Heap * php, Element e)
{
	int i;
	Element temp;
	if(!php)
		return;
	if(php->n == MAX_ELEMENTS)
	{
		fprintf(stderr, "heap full.\n");
		exit(EXIT_FAILURE);
	}
	i = ++(php->n);
	
	//下面方法效率有点低， 应该是先找位置，在插数据,注释中的方法性能更好
	/*
	while(i != 1 && e.key > php->heap[i/2].key)
	{
		heap[i] = heap[i/2];
		i /= 2;
	}
	php->heap[i] = e;
	*/
	/*
	折半法查找,可以实现复杂度为loglog(n)

	*/
	php->heap[i] = e;
	while(i != 1 && e.key > php->heap[i/2].key)
	{
		temp = php->heap[i/2];
		php->heap[i/2] = php->heap[i];
		php->heap[i] = temp;
		i /= 2;
	}
}

Element pop(Heap *php)
{
	int i;
	Element e, item;
	int child;
	
	i = 1;
	child = 2;
	if(php->n == 0)
	{
		fprintf(stderr, "heap empty.\n");
		exit(EXIT_FAILURE);
	}
	e = php->heap[i];
	item = php->heap[(php->n)--];
	while(child <= php->n)
	{
		if(child + 1 <= php->n && php->heap[child+1].key > php->heap[child].key)
			child++;
		if(item.key > php->heap[child].key)
			break;
		php->heap[i] = php->heap[child];
		i = child;
		child = 2 * i;
	}
	php->heap[i] = item;
	
	return e;
}

void initHeap(Heap *php)
{
	if(!php)
		return;
	php->n = 0;
}

void showHeap(Heap * php)
{
	int i;
	if(NULL == php)
		return;
	
	for(i = 1; i <= php->n; i++)
	{
		printf("%d\t", php->heap[i].key);
		if(i % 5 == 0)
			printf("\n");
	}
	printf("\n");
}

void setvalue(Heap * php, int index, int value)
{
	Element temp;
	int oldkey;
	
	if(!php)
		return;
	
	oldkey = php->heap[index].key;
	php->heap[index].key = value;
	temp = php->heap[index];
	
	if(value > oldkey)//增大
	{
		while (index != 1 && value > php->heap[index/2].key)
		{
			php->heap[index] = php->heap[index/2];
			index /= 2;
		}
	}
	else
	{
		int child;
		child = 2 *index;
		while(child <= php->n)
		{
			if(child < php->n && php->heap[child+1].key > php->heap[child].key)
				child++;
			if(temp.key >= php->heap[child].key)
				break;
			php->heap[index] = php->heap[child];
			index = child;
			child = child * 2;
		}		
	}
	php->heap[index]= temp;
}
