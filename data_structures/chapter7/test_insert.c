#include "sort.h"
#include <stdlib.h>
#include <time.h>

void show(Element arr[], int n);
void initList(List *plist, int n);
void showlist(List plist);
int main()
{
	Element arr[LENGTH+1];

	int i;
	List plist;
	
	
	srand(time(0));
	//initList(&plist, LENGTH);
	for(i = 1; i < LENGTH+1; i++)
		arr[i].key = rand()%LENGTH;
	printf("Init arr: \n");
	show(&arr[1], LENGTH);
	/*
	printf("After sort by binSearch: \n");
	//insertSort(arr, LENGTH);
	insertSort_im1(arr, LENGTH);
	show(arr, LENGTH);
	*/
	/*
	printf("Init list: \n");
	showlist(plist);
	printf("After sort by list: \n");
	insertSort_im2(plist);
	showlist(plist);
	*/
	/*
	printf("After sort by quickSort: \n");
	quickSort_im(arr, 0, LENGTH -1);
	show(arr, LENGTH);
	*/
	/*
	printf("After sort by mergerSort: \n");
	mergeSort(arr, LENGTH);
	show(arr, LENGTH);
	*/
	
	printf("After sort by heapSort: \n");
	heapSort(arr, LENGTH);
	show(&arr[1], LENGTH);
	
	return 0;
}

void show(Element arr[], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t", arr[i].key);
		if(i % 10 == 9)
			printf("\n");
	}
	printf("\n");	
}

void initList(List * plist, int n)
{
	Node * head;
	Node * pnode;
	int i;
	
	if(n < 0)
		return;
	head = (Node *)malloc(sizeof(Node));
	head->link = NULL;
	*plist = head;
	
	for(i = 0; i < n; i++)
	{
		pnode = (Node *)malloc(sizeof(Node));
		pnode->e.key = rand() % LENGTH;
		pnode->link = head->link;
		head->link = pnode;
	}
	
}

void showlist(List plist)
{
	int count = 0;
	
	while(plist->link)
	{
		printf("%d\t", plist->link->e.key);
		plist = plist->link;
		if(count++ % 10 == 9)
			printf("\n");
	}
	printf("\n");
}
