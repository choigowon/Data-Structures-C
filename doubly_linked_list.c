#include <stdio.h>
#include <stdlib.h>

typedef struct node { // 이중 연결 리스트 노드
	int value;
	struct node* next;
	struct node* prev;
}node;

node* head = NULL;
