#include <stdio.h>
#include <stdlib.h>

void recursive(int n) {
	if (n == 0)
		return;
	recursive(n - 1);
	printf("%d ", n); // 재귀 호출 이후에 실행되므로 결과는 역순
}

int power(int x, int y) { // x의 y 거듭제곱
	if (y == 0)
		return 1;
	return x * power(x, y - 1);
}

int main() {
	recursive(3);
	printf("\n%d\n", power(2, 3));
	return 0;
}
