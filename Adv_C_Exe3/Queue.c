#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	// add your code here
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* p = (intNode*)malloc(sizeof(intNode));
	if (p == NULL) {
		printf("memory allocation problem\n");
		return;
	}
	p->data= data;
	p->next = NULL;

	if (isEmptyQueue(q))
	{
		q->tail->next = p;
	}
	else
	{
		q->head = p;
	}
	q->tail = p;

}

unsigned int dequeue(Queue* q)
{
	int temp = q->head->data;
	intNode* p = q->head;
	q->head = q->head->next;

	if (q->head == NULL) {
		q->tail = NULL;
	}
	free(p);
	return temp;
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL && q->tail == NULL)
		return 1;
	else return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// add your code here
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	// add your code here
}