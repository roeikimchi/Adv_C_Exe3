#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	free(s); 
}

void push(Stack* s, char data)
{
	charNode* newnode; 
	newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode == NULL)
		return;
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
	// add your code here
}

int isPalindrome(Stack* s)
{
	// add your code here
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
	charNode* tmp = head;
	*head = (*head)->next;
	free(tmp);
}