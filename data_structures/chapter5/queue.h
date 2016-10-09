#include <stdio.h>
#include <stdlib.h>

#define QSIZE 100

typedef struct Elem{
	void * elem;
	/*other field*/
} Elem;

typedef struct Queue{
	Elem elem[QSIZE];
	int front;
	int rear;
}Queue;

int initQueue(Queue * pq);
int enqueue(Queue * pq, const Elem * pe);
int dequeue(Queue * pq, Elem * pe);
int isFull(const Queue * pq);
int isEmpty(const Queue * pq);
