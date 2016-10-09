#include "list.h"
#include <stdlib.h>
#include <memory.h>

void initList(NodePointer * plist)
{
	NodePointer pnode;
	
	if(plist == NULL)
	{
		printf("initList error.\n");
		exit(1);
	}
	pnode = (NodePointer)malloc(sizeof(Node));
	if(!pnode)
	{
		printf("initList malloc error.\n");
		exit(1);
	}
	pnode->link = pnode;
	*plist = pnode;
	return ;
}


int insertList(NodePointer * plist, const Element * e) //尾部插入
{
	NodePointer pnode, rear;
	
	pnode = (NodePointer)malloc(sizeof(Node));
	if(!pnode)
	{
		printf("insertList malloc error.\n");
		return 0;
	}
	rear = (*plist);
	while(rear->link != *plist)
		rear = rear->link;
	pnode->elem = *e;
	pnode->link = *plist;
	rear->link = pnode;
	
	return 1;
}

int deleteList(NodePointer * plist, const Element * e) //根据e删除一个节点
{
	NodePointer pnode, prev;
	
	prev = (*plist);
	pnode = (*plist)->link;
	while(pnode != *plist)
	{
		if(memcmp(&(pnode->elem), e, sizeof(Element)) == 0)
		{
			prev->link = pnode->link;
			free(pnode);
			return 1;
		}
		prev = pnode;
		pnode = pnode->link;
	}
	return 0;
}

NodePointer invertList(NodePointer  list)//反转一个链表
{
	NodePointer current, prev;
	NodePointer temp;
	
	prev = list;
	current = prev->link;
	while(current != list)
	{
		temp = current->link;
		current->link = prev;
		prev = current;
		current = temp;
	}
	current->link = prev;
	
	return current;
}


void destoryList(NodePointer * plist)
{
	NodePointer pnode, temp;
	
	pnode = (*plist)->link;
	while(pnode != *plist)
	{
		temp = pnode;
		pnode = pnode->link;
		free(temp);
	}
	free(pnode);
}

void showList(const NodePointer * plist)
{
	NodePointer pnode;
	int count = 0;
	
	pnode = (*plist)->link;
	while(pnode != *plist)
	{
		printf("%d\t", (pnode->elem).data);
		pnode = pnode->link;
		if(count++ % 5 == 4)
			printf("\n");
	}
}

void catList(NodePointer pa, NodePointer pb)
{
	NodePointer temp, reara, rearb;
	
	if(pb->link == pb)
		return ;
	
	reara = pa->link;
	while(reara->link != pa)
		reara = reara->link;
	
	rearb = pb->link;
	while(rearb->link != pb)
		rearb = rearb->link;
	
	reara->link = pb->link;
	rearb->link = pa;
	
}