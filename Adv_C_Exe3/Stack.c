#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeItem(charNode* head);
charNode* addToHead(charNode* head, charNode* toadd);
printStack(Stack* s);
Stack copyStack(Stack* s);
void reverseStack(Stack* s);
int StackSize(Stack* s);

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

charNode* addToHead(charNode* head, charNode* toadd)//add node to the top of stack (by node)
{
	toadd->next = head;
	head = toadd;
	return head;
}

void removeItem(charNode** head)//remove the node that the function gets
{
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
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
			while (isEmptyStack(&to_rev) != 0 && *ptr_sen != '\0')//pop all items from stack and print them (in different order)
			{
				printf("%c", pop(&to_rev));
			}
		}
		ptr_sen++;
	}
}

int isPalindrome(Stack* s)
{
	if (isEmptyStack(s) == 1)//case stack is empty
		return 1;
	Stack original, s1, s2;
	initStack(&s1);
	initStack(&s2);
	initStack(&original);
	original = copyStack(s);
	s1 = copyStack(s);
	reverseStack(&s1);
	while (isEmptyStack(&s1) == 0 && isEmptyStack(&original) == 0)//compare between the poped data of the original stack and the reverse one
	{
		if (pop(&s1) != pop(&original))
			return 0;
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	if (isEmptyStack(s) == 1)//case stack is empty
	{
		printf("\nstack is empty!\n");
		return;
	}
	int size = StackSize(s);
	if (n < 0 || n > size)
		return;
	Stack original, s1, s2;
	initStack(&s1);
	initStack(&s2);
	initStack(&original);
	for (int i = 0; i < size - n; i++)
	{
		push(&s1, pop(s));
	}
	while (isEmptyStack(s) == 0)
	{
		push(&s2, pop(s));
	}
	destroyStack(s);
	while (isEmptyStack(&s1) == 0)
	{
		push(s, pop(&s1));
	}
	while (isEmptyStack(&s2) == 0)
	{
		push(s, pop(&s2));
	}
}

void reverseStack(Stack* s)
{
	if (isEmptyStack(s) == 1)
		return;
	int size = StackSize(s);
	Stack s1, s2;
	initStack(&s1);
	initStack(&s2);
	while (isEmptyStack(s) == 0)
	{
		push(&s1, pop(s));
	}
	while (isEmptyStack(&s1) == 0)
	{
		push(&s2, pop(&s1));
	}
	while (isEmptyStack(&s2) == 0)
	{
		push(s, pop(&s2));
	}
	destroyStack(&s1);
	destroyStack(&s2);
}

int StackSize(Stack* s) 
{	
	if (isEmptyStack(s) == 1)
		return 0;
	int counter = 0; 
	Stack newStack;
	initStack(&newStack);
	while (isEmptyStack(s) == 0)
	{
		counter++;
		push(&newStack, pop(s));
	}
	destroyStack(s);
	while (isEmptyStack(&newStack) == 0)
	{
		push(s, pop(&newStack));
	}
	destroyStack(&newStack);
	return counter;
}

Stack copyStack(Stack* s)
{
	if (isEmptyStack(s) == 1)
		return;
	int size = StackSize(s);
	Stack s1, s2;
	initStack(&s1);
	initStack(&s2);
	while (isEmptyStack(s) == 0)
	{
		push(&s1, pop(s));
	}
	char tav;
	for (int i = 0; i < size; i++)
	{
		tav = pop(&s1);
		push(&s2, tav);
		push(s, tav);
	}
	return s2;
}