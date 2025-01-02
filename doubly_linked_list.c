#include <stdio.h>
#include <stdlib.h>

typedef struct node { // 이중 연결 리스트 노드
	int value;
	struct node* next;
	struct node* prev;
}node;

node* head = NULL;
node* tail = NULL;

void insert_head(int data) { // 맨 앞에 노드 삽입
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

void insert_tail(int data) { // 맨 뒤에 노드 삽입
	node* new = (node*)malloc(sizeof(node));
	new->value = data;
	new->prev = new->next = NULL;
	if (head = NULL) {
		head = tail = NULL;
		return;
	}
	tail->next = new;
	new->prev = tail;
	tail = new;
}

void remove() { // 맨 앞 노드 제거
	if (head == NULL) {
		return;
	}
	if (head->next == NULL) { // node가 1개인 경우
		free(head);
		head = tail = NULL;
		return;
	}
	node* del = (node*)malloc(sizeof(node));
	del = head;
	head = head->next;
	free(del);
	head->prev = NULL;
}
