#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
}node;

node* head = NULL;
node* create(int value) {
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	new->next = NULL;
	return new;
}

void build(int n) {
	node* tail;
	head = create(1);
	tail = head;
	for (int i = 2; i <= n; i++) {
		tail->next = create(i);
		tail = tail->next;
	}
	tail->next = head;
}

int josephus(int n, int k) {
	build(n);
	node* cur, * del;
	cur = head;
	while (n > 1) {
		for (int i = 0; i < k - 2; i++) {
			cur = cur->next;
		}
		del = cur->next;
		cur->next = del->next;
		free(del);
		n--;
		cur = cur->next;
	}
	return 0;
}

int main() {
	int n, k;
	printf("\n\t\t***Josephus problem***\n\n");
	printf("\t\t처형을 기다리는 사람은 몇 명입니까? ");
	scanf_s("%d", &n);
	printf("\n\n\t\t1번 ~ %d번의 처형 대기자가 있습니다.\n", n);
	printf("\t\t몇 번째 사람을 처형하겠습니까? ");
	scanf_s("%d", &k);
	printf("\n\n\t\t생존자는 &d번 입니다.\n", josephus(n, k));
	return 0;
}
