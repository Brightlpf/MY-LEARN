#include <stdio.h>

typedef struct Item{
	int m_item;
	/**/
}Item;

typedef struct Node{
	int key;
	Item item;
}Node;

typedef struct Tree{
	Node node;
	struct Tree * lchild;
	struct Tree * rchild;
}Tree;

typedef struct Tree * TreePointer;

const Tree * mybsearch(const Tree * tree, int key);
int binsert(TreePointer * ptree, const Node * nd);
int bdelete(TreePointer * ptree, int key);
void threeWayJoin(Tree * small, Tree * mid, Tree * big);
void twoWayJoin(Tree * small, Tree * big);
void split(Tree * tree, int k, Tree * small, Tree * mid, Tree * big);
void show(TreePointer tree);