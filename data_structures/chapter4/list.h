#include <stdio.h>

//封装一个带头循环单链表
typedef struct Element{
	int data;
	//other field
} Element;

typedef struct Node{
	Element elem;
	struct Node * link;
}Node;

typedef Node * NodePointer;

void initList(NodePointer * plist);
int insertList(NodePointer * plist, const Element * e); //尾部插入
int deleteList(NodePointer * plist, const Element * e); //根据e删除一个节点
NodePointer invertList(NodePointer list);//反转一个链表
void catList(NodePointer pa, NodePointer pb);//将pb连接到pa上
void destoryList(NodePointer * plist);
void showList(const NodePointer * plist);