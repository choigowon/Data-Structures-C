#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	int* arr;
	int front;
	int rear;
	int count;
	int cap;
}queue;

void init(queue* p, int size) {
	p->arr = (int*)malloc(sizeof(int) * size);
	p->front = 0;
	p->rear = 0;
	p->count = 0;
	p->cap = size;
}

void enqueue(queue* p, int data) {
	if (p->count == p->cap) {
		printf("\n\n\t\tqueue overflow\n");
		return;
	}
	p->arr[p->rear++] = data;
	p->count++;
	if (p->rear == p->cap) {
		p->rear = 0;
	}
}

int dequeue(queue* p) {
	int del;
	if (p->count == 0) {
		return -99999;
	}
	del = p->arr[p->front++];
	p->count--;
	if (p->front == p->cap) {
		p->front = 0;
	}
	return del;
}

void print(const queue* p) {
	if (p->count == 0) {
		printf("\n\n\t\tempty\n");
		return;
	}
	printf("\n\nqueue display(FIFO)\n");
	for (int i = p->front; i < p->front + p->count; i++) {
		printf("%d ", p->arr[i % p->cap]);
	}
	puts("");
}

void clear(queue* p) {
	p->count = p->front = p->rear = 0;
}

int main() {
	int choice, data;

	queue que;
	init(&que, 5);

	while (1) {
		system("cls");
		printf("\n\n\t\t***circular queue***\n\n");
		printf("1. enqueue   2. dequeue   3. print   4. clear   0. terminate\n");
		printf("choice: ");
		scanf_s("%d", &choice);
		while (getchar() != '\n');
		switch (choice) {
		case 1:
			printf("\n\n\t\tinput: ");
			scanf_s("%d", &data);
			while (getchar() != '\n');
			enqueue(&que, data);
			break;
		case 2:
			data = dequeue(&que);
			if (data == -99999)
				printf("\n\n\t\tqueue underflow\n");
			else
				printf("\n\n\t\t%d dequeue", data);
			break;
		case 3:
			print(&que);
			break;
		case 4:
			clear(&que);
			break;
		case 0:
			free(que.arr);
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}
