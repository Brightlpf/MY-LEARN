#include <stdio.h>
#include <stdlib.h>

#define DQSIZE 10
#define LEFT 0
#define RIGHT 1

typedef struct Element{
	int key;
	/*other field*/
} Element;

typedef struct Node{
	struct Node * next;
	Element elem;
} Node;

typedef struct Deque{
	int qsize;
	Node * left;
	Node * right;
} Deque;

int initDq(Deque * dq);
int addDq(Deque *dq, const Element * e, int flag); //flag = 0 左边插入， flag = 1, 右边插入
int deleteDq(Deque * dq, Element * e, int flag);//flag = 0 左边删除， flag = 1, 右边删除
int destoryDq(Deque * dq);
int isFull(Deque *dq);
int isEmpty(Deque *dq);

int main(void)
{
	Deque q;
	int i;
	Element e;
	
	initDq(&q);
	printf("left in: \n");
	for(i = 0; i < DQSIZE + 1; i++)
	{
		e.key = 2 * i + 1;
		if(isFull(&q))
		{
			printf("deque is full.\n");
			break;
		}
		addDq(&q, &e, LEFT);
		printf("%d\t", e.key);
		if(i % 5 == 4)
			printf("\n");
	}	
	printf("right out: \n");
	for(i = 0; i < DQSIZE + 1; i++)
	{
		e.key = 2 * i + 1;
		if(isEmpty(&q))
		{
			printf("deque is empty.\n");
			break;
		}
		deleteDq(&q, &e, RIGHT);
		printf("%d\t", e.key);
		if(i % 5 == 4)
			printf("\n");
	}
	printf("right in: \n");
	for(i = 0; i < DQSIZE + 1; i++)
	{
		e.key = 2 * i + 1;
		if(isFull(&q))
		{
			printf("deque is full.\n");
			break;
		}
		addDq(&q, &e, RIGHT);
		printf("%d\t", e.key);
		if(i % 5 == 4)
			printf("\n");
	}	
	printf("left out: \n");
	for(i = 0; i < DQSIZE + 1; i++)
	{
		e.key = 2 * i + 1;
		if(isEmpty(&q))
		{
			printf("deque is empty.\n");
			break;
		}
		deleteDq(&q, &e, LEFT);
		printf("%d\t", e.key);
		if(i % 5 == 4)
			printf("\n");
	}
	printf("left in: \n");
	for(i = 0; i < DQSIZE + 1; i++)
	{
		e.key = 2 * i + 1;
		if(isFull(&q))
		{
			printf("deque is full.\n");
			break;
		}
		addDq(&q, &e, LEFT);
		printf("%d\t", e.key);
		if(i % 5 == 4)
			printf("\n");
	}	
	printf("left out: \n");
	for(i = 0; i < DQSIZE + 1; i++)
	{
		e.key = 2 * i + 1;
		if(isEmpty(&q))
		{
			printf("deque is empty.\n");
			break;
		}
		deleteDq(&q, &e, LEFT);
		printf("%d\t", e.key);
		if(i % 5 == 4)
			printf("\n");
	}
	destoryDq(&q);
	
	return 0;
}

int initDq(Deque * dq)
{
	if(NULL == dq)
		return -1;
	
	dq->qsize = 0;
	dq->left = dq->right = NULL;
	return 1;
}

int addDq(Deque *dq, const Element * e, int flag)
{
	Node * pnode;
	
	if(NULL == dq || e == NULL ||(flag != 0 && flag != 1))
	{
		printf("addDq parameter error.\n");
		return -1;
	}
		
	if(isFull(dq))
	{
		return 0;
	}
	
	if((pnode = (Node *)malloc(sizeof(Node))) == NULL )
		return 0;
	
	pnode->elem = *e;
	pnode->next = NULL;
	
	if(isEmpty(dq)) 
	{
		dq->left = dq->right = pnode;
		dq->qsize++;
		return 1;
	}
	
	if(flag == 0)//left
	{
		pnode->next = dq->left;
		dq->left = pnode;
	}
	else 
	{
		dq->right->next = pnode;
		dq->right = pnode;
	}
	dq->qsize++;
	
	return 1;	
}

int deleteDq(Deque * dq, Element * e, int flag)
{
	Node * pnode;
	
	if(NULL == dq || NULL == e ||(flag != 0 && flag != 1))
	{
		printf("addDq parameter error.\n");
		return -1;
	}
	
	if(isEmpty(dq))
		return 0;
	
	if(flag == 0)
	{
		if(dq->left->next == NULL)//只有一个节点
		{
			*e = dq->left->elem;
			free(dq->left);
			dq->left = dq->right = NULL;
		}
		else
		{
			*e = dq->left->elem;
			pnode = dq->left;
			dq->left = dq->left->next;
			free(pnode);
		}
		dq->qsize--;
		return 1;
	}
	else
	{
		if(dq->left->next == NULL)//只有一个节点
		{
			*e = dq->left->elem;
			free(dq->left);
			dq->left = dq->right = NULL;
		}
		else
		{
			pnode = dq->left;
			while(pnode->next != NULL)//寻找指向rear的指针
			{
				if(pnode->next->next == NULL)
				{
					break;
				}
				pnode = pnode->next;
			}
			*e = dq->right->elem;
			free(dq->right);
			pnode->next = NULL;
			dq->right = pnode;
		}
		dq->qsize--;
		return 1;
	}
		
}

int destoryDq(Deque * dq)
{
	Element temp;
	if(dq == NULL)
		return 1;
	while(!isEmpty(dq))
	{
		deleteDq(dq, &temp, LEFT);
	}
	return 1;
}
int isFull(Deque *dq)
{
	if(dq->qsize == DQSIZE)
		return 1;
	return 0;
}

int isEmpty(Deque *dq)
{
	if(dq->qsize == 0)
		return 1;
	return 0;
}
