#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeItem(charNode* head);
charNode* addToHead(charNode* head, charNode* toadd);
printStack(Stack* s);

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	charNode* ptr = s->head; 
	if (s->head == NULL)
		return;
	if (s->head->next == NULL)
	{
		free(s->head);
		s->head = NULL;
		return;
	}
	while (ptr->next != NULL)
	{
		if (ptr->next->next == NULL) 
		{
			charNode* temp = ptr->next;
			ptr->next = NULL;
			free(temp);
			break;
		}
		ptr = ptr->next;
	}
	destroyStack(s);
}

void push(Stack* s, char data)
{
	charNode* newnode; 
	newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode == NULL)
	{
		printf("memory allocation problem\n");
		return;
	}
	newnode->data = data;
	s->head = addToHead(s->head, newnode);
}

char pop(Stack* s)
{
	char tav = s->head->data;
	removeItem(&(s->head));
	return tav;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL) 
	{
		return 1;
	}
	return 0; 
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	char* ptr_sen = sentence;
	Stack to_rev;
	initStack(&to_rev);
	while (*ptr_sen != '\0')
	{
		if (*ptr_sen != '#')
		{
			printf("%c", *ptr_sen);
		}
		if (*ptr_sen == '#')
		{
			if (*(ptr_sen + 1) == '\0')
				return;
			++ptr_sen;
			while (*ptr_sen != '#' && *ptr_sen != '\0')
			{
				push(&to_rev, *ptr_sen);
				++ptr_sen;
			}
			while (to_rev.head != NULL && *ptr_sen != '\0')
			{
				printf("%c", pop(&to_rev));
			}
		}
		ptr_sen++;
	}
}


int isPalindrome(Stack* s)
{
	int res = 0;
	if (isEmptyStack(s) == 1)
		return 1;

	Stack compareStack;
	initStack(&compareStack);
	Stack* compareStackPtr = &compareStack;
	charNode* ptr = s->head;
	while (ptr != NULL)
	{
		push(compareStackPtr, ptr->data);
		ptr = ptr->next;
	}

	charNode* ptrOrig = s->head;
	charNode* ptrComp = compareStackPtr->head;
	
	while (ptrOrig != NULL && ptrComp != NULL)
	{
		if (ptrOrig->data != ptrComp->data)
		{
			return 0;
		}
		ptrOrig = ptrOrig->next;
		ptrComp = ptrComp->next;
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	if (isEmptyStack(s) == 1)
		return;
	charNode* ptr = s->head;
	int counter = 0;
	if (n < 0)
		return;
	
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr->next;
	}

	if (n > counter)
		return;

	Stack temp_s1;
	initStack(&temp_s1);
	Stack temp_s2;
	initStack(&temp_s2);
	Stack* temp1s = &temp_s1;
	Stack* temp2s = &temp_s2;
	for (int i = 0; i < (counter - n) ; i++)
	{
		push(temp1s, pop(s));
	}
	while (s->head != NULL)
	{
		push(temp2s, pop(s));
	}
	destroyStack(s);
	while (temp1s->head != NULL)
	{
		push(s, pop(temp1s));
	}
	while (temp2s->head != NULL)
	{
		push(s, pop(temp2s));
	}
}

charNode* addToHead(charNode* head, charNode* toadd) 
{
	toadd->next = head;
	head = toadd;
	return head;
}

void removeItem(charNode **head) 
{
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

printStack(Stack* s)
{
	if (isEmptyStack(s) == 1)
	{
		printf("\nStack is empty!\n");
		return;
	}
	charNode* ptr = s->head;
	printf("\n");
	while (ptr->next != NULL)
	{
		printf("%c -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("%c\n", ptr->data);
}