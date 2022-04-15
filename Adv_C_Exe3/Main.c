#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	Stack s1;
	initStack(&s1);
	char c1 = 'a';
	char c2 = 'b';
	int num = isEmptyStack(&s1);
	push(&s1,c1);
	push(&s1, c2);
	//char c3 = pop(&s1);
	num = isEmptyStack(&s1);
	destroyStack(&s1);
	int omri = isPalindrome(&s1);
	const char arr[11] = "abgdsa#\0";
	flipBetweenHashes(arr);
}