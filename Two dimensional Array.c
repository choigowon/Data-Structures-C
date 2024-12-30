#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p[3]; // 2차원 배열의 각 배열을 가리키는 포인터 배열
	for (int i = 0; i < 3; i++)
	{
		p[i] = (int*)malloc(sizeof(int) * 4);
	}

	// p[0][1] == *(p[0] + 1)
	// p[2][3] == *(p[2] + 3)
	// 즉, 2차원 배열은 포인터 배열로 연속적인 메모리를 할당해서 만들어진 구조
	
	int num = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			p[i][j] = num++;
			printf("%4d", p[i][j]);
		}
		puts("");
	}
	
	for (int i = 0; i < 3; i++)
	{
		free(p[i]);
	}
	
	return 0;
}
