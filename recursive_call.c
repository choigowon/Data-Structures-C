#include <stdio.h>
#include <stdlib.h>

void recursive(int n) {
	if (n == 0)
		return;
	recursive(n - 1);
	printf("%d ", n); // 재귀 호출 이후에 실행되므로 결과는 역순
}

int main() {
	recursive(3);
	return 0;
}
