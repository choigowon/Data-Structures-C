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

int main()
{
	insert("hello");
	insert("odd");
}
