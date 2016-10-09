#include "heap.h"
#include <stdlib.h>


void initHeap(Heap *php)
{
	php->n = 0;
}

void push(Heap * php, Element e)
{
	int index;
	
	if(NULL == php)
		return;
	/*
	1. 准备存储空间。
	2. 查找位置
	3. 插入数据
	*/
	if(php->n == MAX_ELEMENTS -1)
	{
		printf("heap fulled.\n");
		exit(1);
	}
	index = ++(php->n);
	while(index > 1 && e.key < php->heap[index/2].key)
	{
		php->heap[index] = php->heap[index/2];
		index = index / 2;
	}
	php->heap[index] = e;
	
}

Element pop(Heap *php)
{
	Element ret, last;
	int index = 1;
	int child = 2;

	/*
	1. 保存需要返回的元素。
	2. 调整堆的结构
	*/
	ret = php->heap[1];
	last = php->heap[(php->n)--];
	
	/*
	1. 找出子结点中较小的结点。
	2. 将该结点与尾节点比较，较小的放到父节点的位置处。
	3. 将当前索引更新到对应子结点
	4. 从1循环
	*/
	while(2*index <= php->n)
	{
		if(2 *index < php->n && php->heap[2*index + 1].key < php->heap[2*index].key)
		{
			child++;
		}
		if(last.key <= php->heap[child].key)
			break;
		php->heap[index] = php->heap[child];
		index = child;
		child = child * 2;
	}
	php->heap[index] = last;
	
	return ret;
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
	int oldkey;
	Element temp, save;
	int child;
	
	if(NULL == php)
		return;
	oldkey = php->heap[index].key;
	php->heap[index].key = value;
	save = php->heap[index];
	
	if(value < oldkey)
	{
		while(index > 1 && value < php->heap[index/2].key)
		{
			php->heap[index] = php->heap[index/2];
			index = index/2;
		}		
	}
	else
	{
		child = 2 * index;
		while(child <= php->n)
		{
			if(child < php->n && php->heap[child+1].key < php->heap[child].key)
				child++;
			if(value <= php->heap[child].key)
				break;
			php->heap[index] = php->heap[child];
			index = child;
			child = child *2;
		}
	}
	php->heap[index] = save;
}


