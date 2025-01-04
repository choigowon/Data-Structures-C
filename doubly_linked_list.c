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

void remove_head() { // 맨 앞 노드 제거
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

void remove(int target) { // 특정 노드 삭제
	if (head == NULL)
		return;
	node* del = (node*)malloc(sizeof(node));
	if (head->value == target) { // 맨 앞 노드를 삭제하는 경우
		del = head;
		head = head->next;
		free(del);
		head->prev = NULL;
		return;
	}
	if (tail->value == target) { // 맨 뒤 노드를 삭제하는 경우
		del = tail;
		tail = tail->prev;
		free(del);
		tail->next = NULL;
		return;
	}
	del = head;
	while (del->next != NULL) {
		del = del->next;
		if (del->value == target) {
			del->prev->next = del->next;
			del->next->prev = del->prev;
			free(del);
			return;
		}
	}
}

int getCount() { // node 개수 구하기
	int count = 0;
	if (head == NULL)
		return count;
	node* cur = head;
	while (cur != NULL) {
		count++;
		cur = cur->next;
	}
	return count;
}

node* create(int data) { // node 생성
	node* new = (node*)malloc(sizeof(node));
	new->value = data;
	new->prev = new->next = NULL;
	return new;
}

void insert_nth(int n, int data) { // n번째 자리에 노드 삽입
	int count = getCount();
	if (n<1 || n>count + 1) // 예외 상황
		return;
	node* new = create(data);
	if (head == NULL) {
		head = new;
		tail = new;
		return;
	}
	if (n == 1) { // 첫 번째 자리에 삽입
		new->next = head;
		head->prev = new;
		head = new;
		return;
	}
	if (n == count + 1) { // 마지막 자리에 삽입
		tail->next = new;
		new->prev = tail;
		tail = new;
		return;
	}
	node* cur = head;
	for (int i = 0; i < n - 2; i++) { // n번째 node의 이전 node로 이동
		cur = cur->next;
	}
	new->next = cur->next;
	new->prev = cur;
	cur->next = new;
	new->next->prev = new;
}

void reverse() { // node 역순 연결
	if (head == NULL || head->next == NULL)
		return;
	node* cur = head;
	node* temp;
	while (cur != NULL) {
		temp = cur->next;
		cur->next = cur->prev;
		cur->prev = temp;
		if (cur->prev == NULL) {
			head = cur;
			return;
		}
		cur = cur->prev;
	}
}
