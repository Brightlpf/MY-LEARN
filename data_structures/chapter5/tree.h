#include <stdio.h>
#define DEGREE 3

typedef struct Node{
	char ch;
	struct Node * link[DEGREE];
}Node;

typedef Node * NodePointer;

int getTree(NodePointer * ptree);
void showTree(NodePointer * ptree);
int getDegree(const NodePointer *ptree);
void destoryTree(NodePointer * ptree);
void copyTree(NodePointer * dstTree, const NodePointer * srtTree);
int isEqual(const NodePointer *ptree1, const NodePointer * ptree2);
