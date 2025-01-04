#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct stack {
	int arr[SIZE];
	int top;
}stack;

void create(stack* p) {
	p->top = -1;
}

void push(stack* p, int num) {
	if (p->top >= SIZE - 1) {
		printf("\n\n\t\tstack overflow\n");
		return;
	}
	p->arr[++(p->top)] = num;
}

int pop(stack* p) {
	if (p->top == -1) {
		printf("\n\n\t\tstack underflow\n");
		return -1;
	}
	return p->arr[(p->top)--];
}

void display(stack* p) {
	printf("\n\n\t\tstack display(LIFO): ");
	for (int i = p->top; i >= 0; i--) {
		printf("%d", p->arr[i]);
	}
	puts("");
}

void clear(stack* p) {
	p->top = -1;
}

int main()
{
	int choice, value;
	stack stk;
	create(&stk);

	while (1) {
		system("cls");
		printf("\n\n\t\t*** Stack with Array ***\n\n");
		printf("\t\t1. push   2. pop   3. print   4. clear   0. exit\n");
		printf("\t\tchoice: [ ]\b\b");
		scanf_s("%d", &choice);
		while (getchar() != '\n');
		switch (choice) {
		case 1:
			printf("\n\n\t\t정수 입력: ");
			scanf_s("%d", &value);
			while (getchar() != '\n');
			push(&stk, value);
			break;
		case 2:
			value = pop(&stk);
			printf("\n\n\t\t\%d pop\n", value);
			break;
		case 3:
			display(&stk);
			break;
		case 4:
			clear(&stk);
			break;
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}
