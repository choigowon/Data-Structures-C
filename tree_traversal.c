#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int value;
	struct tree* left;
	struct tree* right;
}tree;

tree* add(tree* t, int data) {
	if (t == NULL) {
		t = (tree*)malloc(sizeof(tree));
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}
	else if (t->value > data) {
		t->left = add(t->left, data); // left에 node 추가
	}
	else if (t->value < data) {
		t->right = add(t->right, data);
	}
	return t;
}

int main() {
	tree* root = NULL;
	int choice, data;
	while (1) {
		system("cls");
		printf("\n\n\t\t***Binary Search Tree(BST)***\n\n");
		printf("1. 노드 삽입\n");
		printf("2. 노드 삭제\n");
		printf("3. 노드 검색\n");
		printf("4. 최대값 구하기\n");
		printf("5. 최소값 구하기\n");
		printf("6. 이진 검색 트리 출력(중위순회)\n");
		printf("0. 프로그램 종료\n");
		printf("\n메뉴 선택: ");
		scanf_s("%d", &choice);
		while (getchar() != '\n');
		switch (choice) {
		case 1:
			printf("\n\n삽입할 정수 입력: ");
			scanf_s("%d", &data);
			root = add(root, data);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			break;
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}
