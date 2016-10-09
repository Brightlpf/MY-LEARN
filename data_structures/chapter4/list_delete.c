#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * next;
} Node;

typedef Node * linkPointer;

void insert(linkPointer * first, linkPointer x);
void delete(linkPointer * first, linkPointer trail);

int main(void)
{
	
}

void insert(linkPointer * first, linkPointer x)
{
	Node * temp;
	temp = (Node *)malloc(sizeof(Node));
	if(temp == NULL)
	{
		//
		return ;
	}
	temp->data = 50;
	if(*first)
	{
		temp->next = x->next;
		x->next = temp;
	}
	else
	{
		temp->next = NULL;
		*first = temp;
	}
}

void delete(linkPointer * first, linkPointer trail)
{
	Node * temp;
	
	
	if(!trail)
	{
		temp = (*first)->next;
		*first = (*first)->next;
	}
	else
	{
		temp = trail->next;
		if(temp)
			trail->next = temp->next;
		else
			trail->next = NULL;
	}
	free(temp);
}
