#include <stdio.h>
#include <ctype.h>
#include "Stack.h"
#include "tree.h"
#include <assert.h>
#define DEGREE 3
#define DEBUG 0


int getTree(NodePointer * ptree)
{
	Stack * ps;
	NodePointer  pnode;
	char input;
	Element e;
	int done = 1;
	int alpha = 0;
	int i;
	int count = 0;
	
	ps = initStack();
	
	//跳过其它字符，直到遇到左括号,表示开始
	while((input = getchar()) != '(')
		continue;
	do{
		input = getchar();
		if(isspace(input))//跳过空格
			continue;
		
		switch(input)
		{
			case '('://遇到“（”就把上一个读到的字母入栈
				e.elem = pnode;
				PUSH(ps, e);
				break;
			case ','://遇到逗号无需操作
				
				break;
			case ')':
				if(isEmpty(ps))//栈为空表示输入结束
				{
					done = 0;
				}
				POP(ps, &e);//出栈
				break;
			default://遇到字符
				//申请内存保存字符，并将结点的链域初始化为0
				pnode = (NodePointer)malloc(sizeof(Node));
				if(pnode == NULL)
				{
					printf("getTree malloc error.\n");
					exit(1);
				}
				#if DEBUG
				printf("[debug] malloc space @ %p\n", (void *)pnode);
				#endif
				pnode->ch = input;
				for(i = 0; i < DEGREE; i++)
					pnode->link[i] = NULL;
				
				if(isEmpty(ps))//第一个节点
				{
					*ptree = pnode;
				}
				else
				{
					NodePointer temp;
					getTop(ps, &e);  //获取栈顶元素
					temp = (NodePointer)e.elem;
					for(i = 0; i < DEGREE; i++)
					{
						//将新结点连接到链表中，按顺序由左右表示为第0,1,2个结点
						//链域为空表示还没有插入结点
						if(temp->link[i] == NULL)
						{
							temp->link[i] = pnode;
							break;
						}		
						else//表示当前链域已经插入过结点了
						{
							if(i == DEGREE -1)
							{
								printf("The max degree of tht tree is %d.\n", DEGREE);
								free(pnode);
								return 0;
							}
							continue;
						}
							
					}
				}
				break;
		}
		
	}while(done);
	
	return 1;
}

/*采用递归的方法实现， 每颗树只考虑根节点和子节点，简化问题*/
void showTree(NodePointer * ptree)
{
	int degree;
	int i;
	
	//树为空
	if(*ptree == NULL)
	{
		return;
	}
	
	printf("%c", (*ptree)->ch);
	//获取子树个数，如果子树个数为零就无需输出其它括号或者逗号信息
	//如果子树个数不为零，就把子树当成一个数来显示
	degree = getDegree(ptree);
	if(degree != 0)
	{
		for(i = 0; i < degree; i++)
		{
			if(i == 0)
				printf("(");
			else
				printf(",");
			showTree(&((*ptree)->link[i]));
		}
		printf(")");
	}	
}

int getDegree(const NodePointer *ptree)
{
	int i, count = 0;
	
	if(*ptree == NULL)
		return -1;
	for(i = 0; i< DEGREE; i++)
	{
		if((*ptree)->link[i] != NULL)
			count++;
	}
	return count;
}

/*销毁一个颗树，也需要遍历所有节点，也采用递归方式实现*/
void destoryTree(NodePointer * ptree)
{
	int degree;
	int i;
	
	if(*ptree == NULL)
	{
		return;
	}
	
	degree = getDegree(ptree);
	//如果是叶子结点，直接释放空间
	if(degree == 0)
	{
		#if DEBUG
		printf("[debug] free space %c @ %p\n", (*ptree)->ch, (void *)(*ptree));
		#endif
		free(*ptree);
		*ptree = NULL;//需要把指针置空，因为统计树的度时是根据非空指针来的
		return;
	}
	else
	{
		/*1. 释放子树*/
		for(i = 0; i < degree; i++)
		{
			destoryTree(&((*ptree)->link[i]));
			(*ptree)->link[i] == NULL;
		}
		/*2. 释放树根结点*/
		#if DEBUG
		printf("[debug] free space %c @ %p\n", (*ptree)->ch, (void *)(*ptree));
		#endif
		free(*ptree);
		*ptree = NULL;
	}
}

void copyTree(NodePointer * dstTree, const NodePointer * srtTree)
{
	NodePointer pnode;
	int degree, i;
	
	assert(*srtTree != NULL);
	pnode = (NodePointer)malloc(sizeof(Node));
	if(pnode == NULL)
	{
		printf("copyTree malloc error.\n");
		exit(1);
	}
	pnode->ch = (*srtTree)->ch;
	*dstTree = pnode;
	degree = getDegree(srtTree);
	if(degree == 0)
	{
		for(i = 0; i < degree; i++)
		{
			pnode->link[i] == NULL;
		}
		return;
	}	
	else
	{
		for(i = 0; i < degree; i++)
		{
			copyTree(&(*dstTree)->link[i], &(*srtTree)->link[i]);
		}
	}
}

int isEqual(const NodePointer *ptree1, const NodePointer * ptree2)
{
	int degree1, degree2;
	int i;
	int ret;
	
	assert(*ptree1 && *ptree2);
	if((*ptree1)->ch != (*ptree2)->ch)
	{
		return 0;
	}
	else
	{
		degree1 = getDegree(ptree1);
		degree2 = getDegree(ptree2);
		if(degree1 != degree2)
		{
			return 0;
		}
		
		if(degree1 == 0)
		{
			return 1;
		}
		else
		{
			for(i = 0; i < degree1; i++)
			{
				ret = isEqual(&((*ptree1)->link[i]), &((*ptree2)->link[i]));
				if(!ret)
				{
					return 0;
				}	
			}
			return 1;
		}
	}
}
