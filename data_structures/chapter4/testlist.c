#include "list.h"
#include <stdlib.h>

int main()
{
	NodePointer list;
	NodePointer list2;
	Element e;
	int key;
	int i;
	int ret;
	
	initList(&list);
	initList(&list2);
	for(i = 0; i < 7; i++)
	{
		e.data = 2 * i + 1;
		ret = insertList(&list, &e);
		if(!ret)
		{
			printf("insertList error.\n");
			exit(1);
		}
	}
	for(i = 0; i < 7; i++)
	{
		e.data = 2 * i;
		ret = insertList(&list2, &e);
		if(!ret)
		{
			printf("insertList error.\n");
			exit(1);
		}
	}
	printf("init list1: \n");
	showList(&list);
	printf("\ninit list 2: \n");
	showList(&list2);
	printf("\nafter cat list1, list2: \n");
	catList(list, list2);
	showList(&list);
	printf("\n");
	//printf("\ninput the element need delete: ");
	//scanf("%d", &key);
	//e.data = key;
	//printf("\nafter delete: \n");
	//deleteList(&list, &e);
	//showList(&list);
	
	//printf("\nafter invert : \n");
	//list = invertList(list);
	//showList(&list);
	destoryList(&list);
	//destoryList(&list2);
	
	return 0;
}