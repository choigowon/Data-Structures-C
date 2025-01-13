#include <stdio.h>

typedef struct tree {
	int value;
	struct tree* left;
	struct tree* right;
}tree;

void display(tree* t) {
	if (t) { // 중위 순회
		display(t->left);
		printf("%d ", t->value);
		display(t->right);
	}
}

int main() {
	return 0;
}
