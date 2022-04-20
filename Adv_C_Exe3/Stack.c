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
	if (s->head == NULL)//case stack is empty
		return;
	if (s->head->next == NULL)//free the last item
	{
		free(s->head);
		s->head = NULL;
		return;
	}
	while (ptr->next != NULL)//free all items except the last one
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
	printf("\n");
	char* ptr_sen = sentence;
	Stack to_rev;
	initStack(&to_rev);
	while (*ptr_sen != '\0')//move the ptr till the end of sentence 
	{
		if (*ptr_sen != '#')//print the chars till there is #
		{
			printf("%c", *ptr_sen);
		}
		if (*ptr_sen == '#')
		{
			if (*(ptr_sen + 1) == '\0')//case # is at the end of sentence 
				return;
			++ptr_sen;
			while (*ptr_sen != '#' && *ptr_sen != '\0')//push the chars after the # to temp stack
			{
				push(&to_rev, *ptr_sen);
				++ptr_sen;
			}
			while (to_rev.head != NULL && *ptr_sen != '\0')//pop all items from stack and print them (in different order)
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
	if (isEmptyStack(s) == 1)//case stack is empty
		return 1;
	Stack compareStack;
	initStack(&compareStack);
	Stack* compareStackPtr = &compareStack;
	charNode* ptr = s->head;
	while (ptr != NULL)//copy and flip the stack to a temp stack 
	{
		push(compareStackPtr, ptr->data);
		ptr = ptr->next;
	}

	charNode* ptrOrig = s->head;
	charNode* ptrComp = compareStackPtr->head;
	
	while (ptrOrig != NULL && ptrComp != NULL)//check if stacks are equal
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
	if (isEmptyStack(s) == 1)//case stack is empty
		return;
	charNode* ptr = s->head;
	int counter = 0;
	if (n < 0)//case n is negative
		return;

	while (ptr != NULL)//count how many items in stack
	{
		counter++;
		ptr = ptr->next;
	}

	if (n > counter)//case n is bigger than number of items in stack
		return;

	Stack temp_s1;
	initStack(&temp_s1);
	Stack temp_s2;
	initStack(&temp_s2);
	Stack* temp1s = &temp_s1;
	Stack* temp2s = &temp_s2;
	for (int i = 0; i < (counter - n) ; i++)//push the items that needs to be at buttom to a new stack
	{
		push(temp1s, pop(s));
	}
	while (s->head != NULL)//push the rest of the items to a new stack (the items that needs to be first)
	{
		push(temp2s, pop(s));
	}
	destroyStack(s);//free the original stack
	while (temp1s->head != NULL)//push the items that needs to be at buttom to the original stack 
	{
		push(s, pop(temp1s));
	}
	while (temp2s->head != NULL)//push the rest of the items to the original stack (the items that needs to be first)
	{
		push(s, pop(temp2s));
	}
}

charNode* addToHead(charNode* head, charNode* toadd)//add node to the top of stack (by node)
{
	toadd->next = head;
	head = toadd;
	return head;
}

void removeItem(charNode **head)//remove the node that the function gets
{
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

printStack(Stack* s)
{
	if (isEmptyStack(s) == 1)//case stack is empty
	{
		printf("\nStack is empty!\n");
		return;
	}
	charNode* ptr = s->head;
	printf("\n");
	while (ptr->next != NULL)//print all items in stack except the last one
	{
		printf("%c -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("%c\n", ptr->data);//print the last item in stack
}