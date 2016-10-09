#include "bsearchtree.h"
#include <stdlib.h>

const Tree * mybsearch(const Tree * tree, int key)
{
	if(NULL == tree)
	{
		return NULL;
	}
	if(key == tree->node.key)
		return tree;
	if(key > tree->node.key)
		return mybsearch(tree->rchild, key);
	else
		return mybsearch(tree->lchild, key);
}
/*
{
	while(tree)
	{
		if(key == tree->node.key)
			return tree;
		if(key > tree->node.key)
		{
			tree = tree->rchild;
		}
		else
		{
			tree = tree->lchild;
		}
	}
	return NULL;
}
*/
int binsert(TreePointer * ptree, const Node * nd)
{
	Tree * current = *ptree;
	Tree * prev = NULL;
	Tree * pnew;
	
	while(current)
	{
		if(nd->key == current->node.key)
		{
			return 0;
		}
		prev = current;
		if(nd->key > current->node.key)
			current = current->rchild;
		else
			current = current->lchild;
	}
	
	pnew = (Tree *)malloc(sizeof(Tree));
	pnew->node = *nd;
	pnew->lchild = pnew->rchild = NULL;
	
	if(prev)
	{
		if(nd->key > prev->node.key)
			prev->rchild = pnew;
		else
			prev->lchild = pnew;
	}
	else
		*ptree = pnew;
	
	return 1;
}

int bdelete(TreePointer * ptree, int key)
{
	Tree * current = *ptree;
	Tree * prev = NULL;
	int flag = 0;//找到关键字为1， 没找到为0
	
	/*查找树中是否存在关键字项key, current 指向含key的结点， prev指向其前驱结点*/
	while(current)
	{
		if(key == current->node.key)
		{
			flag = 1;
			break;
		}
		prev = current;
		if(key > current->node.key)
			current = current->rchild;
		else
			current = current->lchild;
	}
	//没有查找到需要删除的结点
	if(!flag)
	{
		return 0;
	}
	//整棵树只有一个结点
	if((*ptree)->lchild == NULL && (*ptree)->rchild == NULL)
	{
		free(*ptree);
		*ptree = NULL;
		return 1;
	}
	//待删除的结点是叶子结点
	if(current->lchild == NULL && current->rchild == NULL)
	{
		if(prev->lchild == current)
			prev->lchild = NULL;
		else
			prev->rchild = NULL;
	}
	//待删除的结点只有一个右子结点
	else if(current->lchild == NULL)
	{
		if(prev->lchild == current)//前驱结点的左指针指向当前结点
			prev->lchild = current->rchild;
		else //前驱结点的右指针指向当前结点
			prev->rchild = current->rchild;
	}
	//待删除的结点只有一个左子结点
	else if(current->rchild == NULL)
	{
		if(prev->lchild == current)
			prev->lchild = current->lchild;
		else
			prev->rchild = current->lchild;
	}
	//待删除的结点有2个子结点
	else
	{
		//寻找左子树中key最大的结点， save保存其前驱结点
		Tree * save = current;
		Tree * temp = current->lchild;
		
		while(temp->rchild)
		{
			save = temp;
			temp = temp->rchild;
		}
		if(save == current)
			save->lchild = temp->lchild;
		else
			save->rchild = temp->lchild;
		current->node = temp->node;
		current = temp;
	}
	free(current);
	return 1;
}

void threeWayJoin(Tree * small, Tree * mid, Tree * big);
void twoWayJoin(Tree * small, Tree * big);
void split(Tree * tree, int k, Tree * small, Tree * mid, Tree * big);
void show(TreePointer tree)
{
	if(tree)
	{
		printf("key = %d, data = %d\n", tree->node.key, tree->node.item.m_item);
		show(tree->lchild);
		show(tree->rchild);
	}
}