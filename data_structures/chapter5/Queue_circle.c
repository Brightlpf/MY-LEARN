#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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

