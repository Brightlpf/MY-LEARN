#include "queue.h"

int initQueue(Queue * pq)
{
	int i;
	Elem e;
	
	if(NULL == pq)
		return 0;
	pq->front = pq->rear = 0;
	e.elem = 0;
	for(i = 0; i < QSIZE; i++)
	{
		pq->elem[i] = e;
	}
	
	return 1;
}

int enqueue(Queue * pq, const Elem * pe)
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

int dequeue(Queue * pq, Elem * pe)
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
