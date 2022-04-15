#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotateStack(Stack* s, int n);
void removeItem(charNode* head);
void PushToRev(Stack* s, char* ptr);
void popTOrev(Stack* s, char* ptr);
charNode* addToHead(charNode* head, charNode* toadd);

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
		if (ptr->next->next == NULL) {
			charNode* temp = ptr->next;
			ptr->next = NULL;
			free(temp);
			break;
			}
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
	if (s->head == NULL) {
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
	charNode* ptr = s->head;
	Stack compareStack;
	initStack(&compareStack);
	while (ptr != NULL)
	{
		push(&compareStack, ptr->data);
		ptr = ptr->next;
	}
	
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}

charNode* addToHead(charNode* head, charNode* toadd) {
	toadd->next = head;
	head = toadd;
	return head;
}

void removeItem(charNode **head) {
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void PushToRev(Stack* s, char* ptr) {

	
}

void popTOrev(Stack* s, char* ptr) {
	while (*ptr != '#')
	{
		*ptr = pop(s);
		ptr++;
	}
}

Stack* copyStack(Stack* s) {

	Stack newstack;
	initStack(&newstack);



	
}