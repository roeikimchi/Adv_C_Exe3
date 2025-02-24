#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

char StackMenu();
char QueueMenu();

void main()
{
	char* sentence;
	printf("To use stack enter 'S', to use queue enter 'Q': ");
	fseek(stdin, SEEK_END, 0);
	char chose = getchar();
	while (chose != 'q' && chose != 'Q' && chose != 's' && chose != 'S')
	{
		printf("\nYou enterd wrong char, Please try again: ");
		fseek(stdin, SEEK_END, 0);
		chose = getchar();
	}

	if (chose == 's' || chose == 'S')
	{
		Stack s1;
		initStack(&s1);
		char tav;
		int res = 0;
		int num_to_rot = 0;
		while (1){
			switch (StackMenu())
			{
			case '1':
				printf("\nEnter the data: ");
				fseek(stdin, SEEK_END, 0);
				tav = getchar();
				push(&s1, tav);
				break;
			case '2':
				printf("\nPop: %c", pop(&s1));
				break;
			case '3':
				res = isEmptyStack(&s1);
				if (res == 1)
					printf("\nThe stack is empty\n");
				if (res == 0)
					printf("\nThe stack isn't empty\n");
				break;
			case '4':
				sentence = "Remem#reb# thi#carp s#tice";
				flipBetweenHashes(sentence);
				printf("\n");

				break;
			case '5':
				res = isPalindrome(&s1);
				if (res == 1)
					printf("\nThe stack is palindrome\n");
				if (res == 0)
					printf("\nThe stack isn't palindrome\n");
				break;
			case '6':
				printf("\nenter number of items from buttom of stack to move: ");
				scanf("%d", &num_to_rot);
				rotateStack(&s1, num_to_rot);
				break;
			case '7':
				destroyStack(&s1);
				printf("\nstack is now empty, you can check it with option 3... \n");
				break;
			case '8':
				printStack(&s1);
				break;
			case '0':
				return;
			default: printf("\nYou enterd wrong char, Please try again. \n");
			}
		}
	}

	if (chose == 'q' || chose == 'Q')
	{
		int new_data = 0;
		int res = 0;
		Queue q1;
		initQueue(&q1);
		while (1){
			switch (QueueMenu())
			{
			case '1':
				printf("\nEnter the data: ");
				scanf("%d", &new_data);
				enqueue(&q1, new_data);
				break;
			case '2':
				printf("\nOut: %d", dequeue(&q1));
				break;
			case '3':
				res = isEmptyQueue(&q1);
				if (res == 1)
					printf("\nThe queue is empty\n");
				if (res == 0)
					printf("\nThe queue isn't empty\n");
				break;
			case '4':
				cutAndReplace(&q1);
				break;
			case '5':
				sortKidsFirst(&q1);
				break;
			case '6':
				rotateQueue(&q1);
				break;
			case '7':
				destroyQueue(&q1);
				printf("\nqueue is now empty, you can check it with option 3... \n");
				break;
			case '8':
				printQueue(&q1);
				break;
			case '0':
				return;
			default: printf("\nYou enterd wrong char, Please try again: \n");
			}
		}
	}
}

char StackMenu() {
	printf("\n\t MAIN MENU:\
			\n 1. Add element to stack \
			\n 2. Delete and get an element from the stack\
			\n 3. Check if stack is empty \
			\n 4. Check flipBetweenHashes function\
			\n 5. Check if stack is palindrome\
			\n 6. Rotate the stack\
			\n 7. Free the stack \
			\n 8. Print all stack items\
			\n 0. Exit \n\
			\n Your choice: ");
	fseek(stdin, SEEK_END, 0);
	char c = getchar();
	return(c);
}
char QueueMenu() {
	printf("\n\t MAIN MENU:\
			\n 1. Add element to queue \
			\n 2. Delete and get an element from the queue\
			\n 3. Check if queue is empty \
			\n 4. Cut and Replace queue\
			\n 5. Sort queue to kids first\
			\n 6. Rotate the queue\
			\n 7. Free the queue \
			\n 8. Print all queue items\
			\n 0. Exit \n\
			\n Your choice: ");
	fseek(stdin, SEEK_END, 0);
	char c = getchar();
	return(c);
}