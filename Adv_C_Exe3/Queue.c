#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printQueue(Queue* q);
int QueueSize(Queue* q);
Queue CopyQueue(Queue* q);
void ReverseQueue(Queue* q);

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	intNode* ptr = q->head;
	if (q->head == NULL && q->tail == NULL)//case queue is empty
		return;
	if (q->head->next == NULL)//free the last item
	{
		free(q->head);
		q->head = q->tail = NULL;
		return;
	}
	while (ptr->next != NULL)//free all items except the last one
	{
		if (ptr->next->next == NULL)
		{
			intNode* temp = ptr->next;
			ptr->next = NULL;
			free(temp);
			break;
		}
		ptr = ptr->next;
	}
	destroyQueue(q);
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* newNode = (intNode*)malloc(sizeof(intNode));
	if (newNode == NULL) {
		printf("memory allocation problem\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;

	if (isEmptyQueue(q))//case queue is empty 
	{
		q->head = newNode;
		q->tail = newNode;
	}
	else//case queue isn't empty
	{
		q->tail->next = newNode;
		q->tail = newNode;
	}
}

unsigned int dequeue(Queue* q)
{
	int temp = q->head->data;
	intNode* p = q->head;
	q->head = q->head->next;
	if (q->head == NULL)//case there is only 1 item in queue
		q->tail = NULL;
	free(p);
	return temp;
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL && q->tail == NULL)
		return 1;
	else return 0;
}

void printQueue(Queue* q)
{
	if (isEmptyQueue(q) == 1)//case queue is empty
	{
		printf("\nQueue is empty!\n");
		return;
	}
	intNode* ptr = q->head;
	printf("\n");
	while (ptr->next != NULL)
	{
		printf("%d <- ", ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	if (isEmptyQueue(q) == 1)//case queue is empty
		return;
	int size = QueueSize(q);
	for (int i = 0; i < size - 1; i++)
	{
		enqueue(q, dequeue(q));
	}
}

void cutAndReplace(Queue* q)
{
	if (isEmptyQueue(q) == 1)//case queue is empty
		return;
	int size = QueueSize(q);//get the size of the queue
	Queue tmp_q;
	initQueue(&tmp_q);
	tmp_q = CopyQueue(q);
	unsigned int sum = 0;
	if (size % 2 != 0)//case there is odd num of items in queue
	{
		while (isEmptyQueue(&tmp_q) == 0)
		{
			sum += dequeue(&tmp_q);
		}
		sum /= size;
		enqueue(q, sum);
		size++;
	}
	Queue q1, q2;
	initQueue(&q1);
	initQueue(&q2);
	for (int i = 0; i < size / 2; i++)//dequeue the first half of original queue to q1
	{
		enqueue(&q1, dequeue(q));
	}
	for (int i = 0; i < size / 2; i++)//dequeue the other half of original queue to q2
	{
		enqueue(&q2, dequeue(q));
	}
	ReverseQueue(&q2);
	while (isEmptyQueue(&q2) == 0)//enqueue the second half reversed to the original queue
	{
		enqueue(q, dequeue(&q2));
	}
	while (isEmptyQueue(&q1) == 0)//enqueue the first half to the original queue
	{
		enqueue(q, dequeue(&q1));
	}
}

void sortKidsFirst(Queue* q)
{
	if (isEmptyQueue(q) == 1)//case queue is empty
		return;
	int size = QueueSize(q);
	unsigned int min, temp;
	Queue q1, q2;
	initQueue(&q1);
	initQueue(&q2);
	while (isEmptyQueue(q) == 0)
	{
		enqueue(&q1, dequeue(q));
	}
	while (QueueSize(q) != size)//until the original queue is full again
	{
		min = dequeue(&q1);
		int duplicates = 1;
		while (isEmptyQueue(&q1) == 0)//dequeue item and check who is the min
		{
			temp = dequeue(&q1);
			if (temp == min)
			{
				duplicates++;
			}
			if (temp < min)
			{
				enqueue(&q2, min);
				min = temp;
			}
			if (temp > min)
			{
				enqueue(&q2, temp);
			}
		}
		for (int i = 0; i < duplicates; i++)//case there is duplicates items
		{
			enqueue(q, min);
		}
		while (isEmptyQueue(&q2) == 0)
		{
			enqueue(&q1, dequeue(&q2));
		}
	}
}

int QueueSize(Queue* q)
{
	int counter = 0;
	Queue tmp;
	initQueue(&tmp);
	while (isEmptyQueue(q) == 0)//dequeue the original queue and count how many items there is in queue
	{
		counter++;
		enqueue(&tmp, dequeue(q));
	}
	destroyQueue(q);
	while (isEmptyQueue(&tmp) == 0)//return the items from temp queue to the original one
	{
		enqueue(q, dequeue(&tmp));
	}
	destroyQueue(&tmp);
	return counter;
}

Queue CopyQueue(Queue* q)
{
	Queue NewQ;
	initQueue(&NewQ);
	int size = QueueSize(q);
	unsigned int val = 0;
	for (int i = 0; i < size; i++)
	{
		val = dequeue(q);
		enqueue(&NewQ, val);
		enqueue(q, val);
	}
	return NewQ;
}

void ReverseQueue(Queue* q)
{
	if (isEmptyQueue(q) == 1)
		return;
	unsigned int data = dequeue(q);

	ReverseQueue(q);

	enqueue(q, data);
}