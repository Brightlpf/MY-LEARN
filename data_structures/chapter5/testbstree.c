#include "bsearchtree.h"
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int i;
	Node node;
	TreePointer tree;
	
	srand(time(NULL));
	tree = NULL;
	
	/*
	for(i =0; i < 10; i++)
	{
		node.key = rand() % 10;
		node.item.m_item = i;
		binsert(&tree, &node);
		printf("insert: key = %d, data = %d\n", node.key, node.item.m_item);
	}
	*/
	node.key = 1;
	node.item.m_item = 0;
	binsert(&tree, &node);
	
	node.key = 8;
	binsert(&tree, &node);
	
	node.key = 3;
	binsert(&tree, &node);
	
	node.key = 2;
	binsert(&tree, &node);
	
	
	node.key = 9;
	binsert(&tree, &node);
	
	printf("after insert: \n");
	show(tree);
	printf("after delete: \n");
	bdelete(&tree, 8);
	show(tree);
	
	return 0;
}