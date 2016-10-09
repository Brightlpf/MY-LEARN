#include "bintree.h"

//这个创建树的函数需要交互输入， 有点麻烦，但是可以建立所有二叉树
//一开始输入根节点， 接着输入左子树、右子树，依次类推，# 表示对应子树为空
BtreePointer create(void)
{
	BtreePointer pnode;
	char temp;
	
	temp = getchar();
	getchar();//skip /n
	if(temp == '#')
		return NULL;
	
	pnode = (BtreePointer)malloc(sizeof(Node));
	if(pnode == NULL)
	{
		return NULL;
	}
	pnode->ch = temp;
	printf("Enter left child data (# to NULL): ");
	pnode->lchild = create();
	printf("Enter right child data(# to NULL): ");
	pnode->rchild = create();
	
	return pnode;
}

void show_vlr(  BtreePointer pbt)//递归
{
	if(pbt == NULL)
		return;
	printf("%c", pbt->ch);
	show_vlr(pbt->lchild);
	show_vlr(pbt->rchild);
}

void show_lvr(  BtreePointer pbt)//递归
{
	if(pbt)
	{
		show_lvr(pbt->lchild);
		printf("%c", pbt->ch);
		show_lvr(pbt->rchild);
	}
}

void show_lrv(BtreePointer pbt)
{
	if(pbt)
	{
		show_lrv(pbt->lchild);
		show_lrv(pbt->rchild);
		printf("%c",pbt->ch);
	}
}

void show_vlr_c(BtreePointer pbt)//循环
{
	Stack * pst;
	Element e;
	int ret;
	int done = 1;
	
	pst = initStack();
	if(pbt == NULL)
		return;
	while(done)
	{
		printf("%c", pbt->ch);
		if(pbt->lchild)
		{
			e.elem = pbt;
			PUSH(pst, e);
			pbt = pbt->lchild;
			continue;
		}
		
		while(!(pbt = pbt->rchild))
		{
			ret = POP(pst, &e);
			if(!ret)
			{
				done = 0;
				break;
			}
			else
			{
				pbt = (BtreePointer)e.elem;
			}	
		}
	}
	destoryStack(pst);
}

void show_lvr_c(BtreePointer pbt)//循环
{
	Stack * pst;
	Element e;
	int ret;
	int done = 1;
	
	pst = initStack();
	if(pbt == NULL)
		return;
	while(done)
	{
		if(pbt->lchild)
		{
			e.elem = pbt;
			PUSH(pst, e);
			pbt = pbt->lchild;
			continue;
		}
		printf("%c", pbt->ch);
		while(!(pbt = pbt->rchild))
		{
			ret = POP(pst, &e);
			if(!ret)
			{
				done = 0;
				break;
			}
			else
			{
				pbt = (BtreePointer)e.elem;
				printf("%c", pbt->ch);
			}	
		}
	}
	destoryStack(pst);
}

void show_lrv_c(BtreePointer pbt)
{
	Stack * pst;
	Element e;
	int ret;
	int done = 1;
	BtreePointer temp;
	
	pst = initStack();
	if(pbt == NULL)
		return;
	while(done)
	{
		if(pbt->lchild || pbt->rchild)//只有要子树就需要将当前根节点入栈
		{
			e.elem = pbt;
			PUSH(pst, e);
			if(pbt->lchild)
				pbt = pbt->lchild;
			else
				pbt = pbt->rchild;
			continue;
		}
		//叶子结点
		while(1)
		{
			printf("%c", pbt->ch);
			temp = pbt;   //保存当前结点，为了判断是否是从左子树返回
			ret = POP(pst, &e);
			if(!ret)
			{
				done = 0;
				break;
			}
			else
			{
				pbt = (BtreePointer)e.elem;
				if(pbt->lchild && pbt->rchild  && (temp == pbt->lchild))
				{
					//如果结点有左右子树，且从左子树返回就重新入栈， 遍历右子树
					PUSH(pst, e);
					pbt = pbt->rchild;
					break;
				}
			}
		}
			
	}
	destoryStack(pst);
}

void show_level( BtreePointer pbt)//层序遍历
{
	Queue q;
	Elem e;
	
	if(!pbt)
		return;
	initQueue(&q);
	
	e.elem = pbt;
	enqueue(&q, &e);
	while(!isEmpty(&q))
	{
		dequeue(&q, &e);
		pbt = (BtreePointer)e.elem;
		printf("%c", pbt->ch);
		if(pbt->lchild)
		{
			e.elem = pbt->lchild;
			enqueue(&q, &e);
		}
		if(pbt->rchild)
		{
			e.elem = pbt->rchild;
			enqueue(&q, &e);
		}			
	}
}

void destory(BtreePointer pbt)
{
	if(pbt == NULL)
		return;
	if(pbt->lchild != NULL)
		destory(pbt->lchild);//销毁左子树
	if(pbt->rchild != NULL)
		destory(pbt->rchild);//销毁右子树
	free(pbt);//释放当前结点
}

int sum_node(BtreePointer pbt)
{
	if(!pbt)
	{
		return 0;
	}
	return sum_node(pbt->lchild) + sum_node(pbt->rchild) + 1;
}
