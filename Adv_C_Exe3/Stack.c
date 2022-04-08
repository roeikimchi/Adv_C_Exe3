#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotateStack(Stack* s, int n);
void removeItem(charNode* head);
void pushTOrev(Stack* s, char* ptr);
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
	char* ptr = sentence;
	/*char new_sentence[strlen(sentence)+1];
	char** ptr = new_sentence;
	strcpy( new_sentence, sentence);*/
	Stack to_REV_sen;
	initStack(&to_REV_sen);

	while (*ptr != '\0')
	{
		if (*ptr == '#') {

			++ptr;
			pushTOrev(&to_REV_sen,ptr);
			popTOrev(&to_REV_sen, ptr);
		}

		ptr++;
	}


	/*int count = 0;
	for (int i = 0; i < strlen(sentence); i++)
	{
		if (sentence[i] == '#')
			count++;
	}
	if (count % 2 == 1)
		count--;
	count /= 2;
	Stack to_REV_sen;
	initStack(&to_REV_sen);
	for (int i = 0; i < ; i++){
		push(&to_REV_sen, sentence[i]);
	}*/
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

void pushTOrev(Stack* s, char* ptr) {

	while (*ptr != '#')
	{
		push(s, *ptr);
		ptr++;
	}
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