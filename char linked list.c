#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char* str; // 문자열의 주소
	struct node* next;
}node;

node* head = NULL;

void insert(char* pstr) { // 맨 앞 삽입
	node* new = (node*)malloc(sizeof(node));
	new->str = (char*)malloc(strlen(pstr) + 1); // node의 문자열에 str의 길이 + null(1)만큼 메모리 할당
	strcpy(new->str, pstr); // pstr이 가리키는 문자열을 node에 복사
	new->next = NULL;

	if (head == NULL) {
		head = new;
		return;
	}
	new->next = head;
	head = new;
}

void remove() { // 전체 노드 제거
	if (head == NULL)
		return;
	node* del;
	while (head != NULL) {
		del = head;
		head = head->next;
		free(del->str); // 문자열도 메모리 할당 후 포인터로 지정했기 때문에 제거 필요
		free(del); // 포인터가 가리키는 메모리가 제거되는거임. 즉 del 노드가 아닌 del 포인터가 가리키는 노드가 제거
	}
}

int main()
{
	insert("hello");
	insert("odd");
}
