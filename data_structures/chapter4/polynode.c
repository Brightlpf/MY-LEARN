#include <stdio.h>
#include <stdlib.h>

//计算多项式相加
typedef struct polyNode{
	int coef;//系数
	int expon;//指数
	struct polyNode * next;
} PolyNode;

typedef PolyNode * PolyPointer;

int compare(int x, int y);
int pinsert(int coef, int expon, PolyPointer * ptr);
PolyPointer padd(PolyPointer a, PolyPointer b);
void attach(int coef, int expon, PolyPointer * c);
void pdestory(PolyPointer * ptr);
void pshow(PolyPointer ptr);

int main(void)
{
	// a = x4 + 3x2 + 5x1 
	// b = 2x3 + 4x2 + 6x1
	PolyPointer a, b, c, temp;
	a = 0;
	b = 0;
	c = 0;
	pinsert(1, 4, &a);
	pinsert(3, 2, &a);
	pinsert(5, 1, &a);
	pinsert(2, 3, &b);
	pinsert(4, 2, &b);
	pinsert(6, 1, &b);
	printf("a = ");
	pshow(a);
	printf("\nb = ");
	pshow(b);
	
	c = padd(a, b);
	
	printf("\nc = ");
	pshow(c);
	printf("\n");
	return 0;
}

PolyPointer padd(PolyPointer a, PolyPointer b)
{
	PolyPointer c, save;
	int sum;
	
	if(NULL == a && b == NULL)
	{
		printf("padd parameter error.\n");
		return NULL;
	}
		
	c = (PolyPointer)malloc(sizeof(PolyNode));//创建一个空节点当表头，方便计算
	if(NULL == c)
	{
		printf("padd malloc error.\n");
		exit(1);
	}
	
	save = c;  //后续表头始终指向尾节点，因此需要保存头结点
	//把a, b归并到c中
	while(a && b)
	{
		switch(compare(a->expon, b->expon))
		{
			case -1:
				attach(a->coef, a->expon, &c);
				a = a->next;
				break;
			case 0:
				sum = a->coef + b->coef;
				if(sum)
					attach(a->coef + b->coef, a->expon, &c);
				a = a->next;
				b = b->next;
				break;
			case 1:
				attach(b->coef, b->expon, &c);
				b = b->next;
				break;
		}
	}
	while(a)
	{
		attach(a->coef, a->expon, &c);
		a = a->next;
	}
	while(b)
	{
		attach(b->coef, b->expon, &c);
		b = b->next;
	}
	c->next = NULL;
	c = save->next;
	free(save);
	
	return c;
}

void attach(int coef, int expon, PolyPointer * ptr)
{
	PolyPointer temp;
	
	if(*ptr == NULL)
	{
		return;
	}
	temp = (PolyPointer)malloc(sizeof(PolyNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->next = NULL;
	(*ptr)->next = temp;
	*ptr = temp; // 始终指向表尾，避免每次都遍历一遍链表
}

int pinsert(int coef, int expon, PolyPointer * ptr)
{
	PolyPointer temp;
	
	temp = (PolyPointer) malloc(sizeof(PolyNode));
	if(!temp)
	{
		return 0;
	}
	temp->coef = coef;
	temp->expon = expon;
	temp->next = NULL;
	if(*ptr)
	{
		temp->next = (*ptr);
		(*ptr) = temp;
	}
	else
	{
		*ptr = temp;
	}
	return 1;
}

void pdestory(PolyPointer * ptr)
{
	PolyPointer temp;
	
	while(*ptr)
	{
		temp = (*ptr)->next;
		free(*ptr);
		(*ptr) = temp;
	}
	
}

void pshow(PolyPointer ptr)
{
	if(ptr == NULL)
		return ;
	while(ptr)
	{
		printf(" %dx%d ", ptr->coef, ptr->expon);
		if(ptr = ptr->next)
			printf("+");
	}
}

int compare(int x, int y)
{
	if(x - y < 0)
		return -1;
	else if(x - y > 0)
		return 1;
	else 
		return 0;
}
