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

int main()
{
	int choice, data;

	while (1) {
		printf("*** 단일 연결 리스트 ***\n\n");
		printf("\n입력: ");
		scanf_s("%d", &choice);
		while (getchar() != '\n');
		switch (choice) {
		case 1:
			printf("\n정수 입력: ");
			scanf_s("%d", &data);
			while (getchar() != '\n');
			insert_node_front(data);
			break;
		case 0:
			exit(0);
		}
	}
	return 0;
}
