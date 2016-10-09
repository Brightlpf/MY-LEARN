#include <stdio.h>
#include "Stack.h"
#include "queue.h"

typedef struct Node
{
	char ch;
	struct Node * lchild;
	struct Node * rchild;
}Node;

typedef Node * BtreePointer;

//v : root  , l: leftchild, r: rightchild, c: recycle
BtreePointer create(void);
void show_vlr(BtreePointer pbt);//先序递归
void show_lvr(BtreePointer pbt);//中序递归
void show_lrv(BtreePointer pbt);//后序递归
void show_vlr_c(BtreePointer pbt);//先序循环
void show_lvr_c(BtreePointer pbt);//中序循环
void show_lrv_c(BtreePointer pbt);//后序循环循环
void show_level(BtreePointer pbt);//层序遍历
int sum_node(BtreePointer pbt);
void destory(BtreePointer pbt);

