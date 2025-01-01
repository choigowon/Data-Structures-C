#include <stdio.h>
#include <stdlib.h>

typedef struct node { // 구조체로 node 만들기
	int value; // 값
	struct node* next; // 다음 node 주소를 저장하는 포인터(8byte)
}node;

node* head = NULL; // 첫 노드의 주소를 저장하는 포인터(8byte)

void insert_node_front(int data) {
	node* new; // 새로운 노드를 가리키는 포인터
	new = (node*)malloc(sizeof(node));
	new->value = data; // new가 가리키는 node의 value
	new->next = NULL; // new가 가리키는 node의 next
	
	if (head == NULL) { // head가 null을 가리키고 있다면
		head = new;
		return;
	}
	
	new->next = head; // 다음 node를 이전 node로 지정
	head = new; // head를 새로운 node로 지정

	// 맨 앞에 노드를 추가하는 것은 다음 포인터를 head로 가리키고
	// head를 추가된 노드를 가리키게 하는 총 2단계를 통해
	// 수행 가능하므로 시간복잡도는 O(1)
}

void display() {
	if (head == NULL) {
		printf("\n\n\t\t출력할 연결 리스트 없음\n");
		return;
	}

	node* cur;
	cur = head;
	
	while (cur->next != NULL) {
		printf("%d -> ", cur->value);
		cur = cur->next;
	}
	printf("%d\n", cur->value);
}

void insert_node_rear() {
	node* new, * cur;
	new = (node*)malloc(sizeof(node));
	scanf_s("%d", &new->value);
	new->next = NULL;
	if (head == NULL) {
		head = new;
		return;
	}
	cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	} // node 개수 만큼 이동해야 하므로 시간 복잡도는 O(N)
	cur->next = new;
}

void del() { // 맨 앞 노드 삭제
	node* del = head;
	if (head == NULL)
		return;
	head = head->next;
	free(del);
}

void remove() { // 전체 노드 삭제
	node* del = head;
	while (head != NULL) {
		head = head->next;
		free(del);
		del = head;
	}
}

node* search(int target) {
	if (head == NULL)
		return NULL;
	node* cur = head;
	while (cur != NULL) {
		if (cur->value == target)
			return cur;
		cur = cur->next;
	}
}

void remove_value(int target) { // 특정 노드 삭제
	if (head == NULL)
		return;
	node* del, * prev;
	del = prev = head;
	if (head->value == target) {
		head = head->next;
		free(del);
		return;
	}
	while (del->next != NULL) {
		del = del->next;
		if (del->value == target) {
			prev->next = del->next;
			free(del);
			return;
		}
		prev = prev->next;
	}
}

void insert() { // 정렬 삽입
	node* new = (node*)malloc(sizeof(node));
	scanf_s("%d", &new->value);
	new->next = NULL;
	if (head == NULL) { // 아무것도 없을 때
		head = new;
		return;
	}
	if (head->value > new->value) { // 가장 작은 값 삽입
		new->next = head;
		head = new;
		return;
	}
	node* cur, * prev;
	cur = prev = head;
	while (cur->next != NULL) { // 중간 값 삽입
		cur = cur->next;
		if (cur->value > new->value) {
			prev->next = new;
			new->next = cur;
			return;
		}
		prev = prev->next;
	}
	cur->next = new; // 가장 큰 값 삽입
}

int main()
{
	int choice, data;

	while (1) {
		system("cls");
		printf("\n\n*** 단일 연결 리스트 ***\n\n");
		printf("1. 맨 앞 노드 삽입\n");
		printf("10. 단일 연결 리스트 출력\n");
		printf("0. 프로그램 종료\n");

		printf("\n선택: ");
		scanf_s("%d", &choice);
		while (getchar() != '\n');
		switch (choice) {
		case 1:
			printf("\n정수 입력: ");
			scanf_s("%d", &data);
			while (getchar() != '\n');
			insert_node_front(data);
			break;
		case 10:
			display();
		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}
