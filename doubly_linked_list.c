#include <stdio.h>
#include <stdlib.h>

typedef struct node { // 이중 연결 리스트 노드
	int value;
	struct node* next;
	struct node* prev;
}node;

node* head = NULL;
node* tail = NULL;

void insert(int data) { // 맨 앞에 노드 삽입
	node* new = (node*)malloc(sizeof(node));
	new->value = data;
	new->prev = new->next = NULL;
	if (head = NULL) {
		head = tail = new;
		return;
	}
	new->next = head;
	head->prev = new;
	head = new;
}
