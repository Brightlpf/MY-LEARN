#include <stdio.h>
#include <stdlib.h>

#define QSIZE 10

typedef struct Element{
	int key;
	/*other field*/
} Element;

typedef struct Queue{
	Element elem[QSIZE];
	int front;
	int rear;
}Queue;

int initQueue(Queue * pq);
int enqueue(Queue * pq, const Element * pe);
int dequeue(Queue * pq, Element * pe);
int isFull(const Queue * pq);
int isEmpty(const Queue * pq);

int main()
{
	Queue q;
	int i;
	Element temp;
	
	initQueue(&q);
	for(i = 0; i < QSIZE + 1; i++)
	{
		if(isFull(&q))
		{
			printf("Queue is fulled.\n");
			break;
		}
		temp.key = 2 * i + 1;
		enqueue(&q, &temp);
		printf("enqueue: %d\t", temp.key);
		if(i % 5 == 4)
			printf("\n");
	}
	
	for(i = 0; i < QSIZE + 1; i++)
	{
		if(isEmpty(&q))
		{
			printf("Queue is empty.\n");
			break;
		}
		dequeue(&q, &temp);
		printf("dequeue: %d\t", temp.key);
		if(i % 5 == 4)
			printf("\n");
	}
	
	for(i = 0; i < 3 * QSIZE + 1; i++)
	{
		temp.key = i + 1;
		enqueue(&q, &temp);
		enqueue(&q, &temp);
		printf("enqueue: %d\t", temp.key);
		dequeue(&q, &temp);
		printf("dequeue: %d\t", temp.key);
		printf("[debug] front = %d, rear = %d\n", q.front, q.rear);
	}
	
	return 0;
}

int initQueue(Queue * pq)
{
	int i;
	Element e;
	
	if(NULL == pq)
		return 0;
	pq->front = pq->rear = 0;
	e.key = 0;
	for(i = 0; i < QSIZE; i++)
	{
		pq->elem[i] = e;
	}
	
	return 1;
}

int enqueue(Queue * pq, const Element * pe)
{
	if(pq == NULL || pe == NULL)
		return -1;
	if(isFull(pq))
		return 0;
	pq->elem[pq->rear++ % QSIZE] = *pe;
	if(pq->rear >= QSIZE)
		pq->rear = 0;
	return 1;
}

int dequeue(Queue * pq, Element * pe)
{
	if(pq == NULL || pe == NULL)
		return -1;
	if(isEmpty(pq))
		return 0;
	*pe = pq->elem[pq->front++ % QSIZE];
	if(pq->front >= QSIZE)
		pq->front = 0;
	return 1;
}

int isFull(const Queue * pq)
{
	if(NULL == pq)
		return -1;
	
	if((pq->rear + 1)%QSIZE == pq->front)
		return 1;
	return 0;
}

int isEmpty(const Queue * pq)
{
	if(NULL == pq)
		return -1;
	if(pq->front == pq->rear)
		return 1;
	return 0;
}
