#include <stdio.h> //전처리기 (preprocessor), 컴파일 전에 실행

int main(void) // main 함수 정의 시작
{ // 영역(scope)의 시작
	int a;
	int b; // 변수 선언
	int c;

	a = 1; // 변수에 값 대입
	b = 2;
	c = a + b; // 변수에 연산 결과 대입

	printf("Result is %i", c); // 함수 호출

	return 0; // 결과 값을 반환
} // 영역(scope)의 끝