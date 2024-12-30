// stack (지역변수, 매개변수): O/S에서 관리
// heap (동적 메모리(런타임 중에 메모리 할당)) : 개발자가 관리. 즉, 직접 메모리 할당 및 제거 작업 필요
// data (전역변수, static) : O/S에서 관리

#include <stdio.h>
#include <stdlib.h> // malloc, free 함수 제공

int main()
{
	int n;
	printf("학생수 입력: ");
	scanf_s("%d", &n);
	
	// int score[n]; // 컴파일 에러
	// 배열을 컴파일 시에 메모리 할당이 필요(정적 할당)하지만, n은 런타임 중에 할당(동적 할당)되므로

	int* score;
	score = (int*)malloc(n * sizeof(int));
	// int(4바이트) n개 크기 만큼 메모리 할당 (heap 영역)
	// 이 메모리를 가리키는 포인터 score (stack 영역)
	// 각 메모리는 score +1, +2, ...로 접근 가능
	// malloc은 void로 리턴하므로 형변환 필요

	free(score); // 포인터가 가리키는 메모리 제거

	// heap 영역은 free 함수로 메모리 제거
	// stack, data 영역은 프로그램이 종료되면 자동으로 제거
}
