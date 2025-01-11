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

int gcd(int x, int y) { // x와 y의 최대공약수
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int main() {
	recursive(3);
	printf("\n2와 3의 거듭제곱: %d\n", power(2, 3));
	printf("72와 30의 최대공약수: %d\n", gcd(72, 30));
	return 0;
}
