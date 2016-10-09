#ifndef HEAP_H_
#define HEAP_H_
#include <stdio.h>
#define MAX_ELEMENTS 200


typedef struct Element{
	int key;
	/*other field*/
}Element;


typedef struct Heap{
	Element heap[MAX_ELEMENTS];
	int n;
}Heap;


void initHeap(Heap *php);
void push(Heap * php, Element e);//插入大根堆
Element pop(Heap *php);//删除根结点
void showHeap(Heap * php);
void setvalue(Heap * php, int index, int value);

#endif