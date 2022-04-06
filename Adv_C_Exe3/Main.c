#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	Stack s1;
	initStack(&s1);
	char c1 = 'a';
	int num = isEmptyStack(&s1);
	push(&s1,c1);
	char c2 = pop(&s1);
	num = isEmptyStack(&s1);
	destroyStack(&s1);
}