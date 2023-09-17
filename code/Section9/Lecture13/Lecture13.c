#include <stdio.h>

int main(void)
{
	int a, b;

	a = 123;

	int* aPtr; // a를 참조하는 포인터
	aPtr = &a;
	printf("%d %d %p\n", a, *aPtr, aPtr); // 123 123 000000A8AA99F844

	*aPtr = 456; // 간접 접근을 통해 값을 변경하면 원래 변수의 값도 변경됨
	printf("%d %d %p\n", a, *aPtr, aPtr); // 456 456 000000A8AA99F844

	// b = aPtr; // 정수형 변수 b에 주소를 할당하려 하면 경고 발생, 하지만 빌드는 됨
	b = *aPtr; // 간접 접근을 통해 b에 a의 값을 할당
	printf("%d\n", b); // 456

	*aPtr = 789; // 간접 접근을 통해 값을 변경해도 b의 값은 바뀌지 않음(메모리 주소가 아예 다름)
	printf("%d\n", b); // 456
	printf("%d %d %p %p\n", a, *aPtr, aPtr, &b); // 789 789 000000A8AA99F844 000000A8AA99F864

	b = 12; // b의 값을 변경해도 a의 값은 바뀌지 않음(a와 b는 아예 다른 변수)
	printf("%d\n", b); // 12
	printf("%d %d %p\n", a, *aPtr, aPtr); // 789 789 000000A8AA99F844

	// 원래 변수의 값을 변경하면 간접 접근을 통해 얻는 값도 변경됨
	// (당연히 간접 접근이 원래 변수의 주소에 있는 값에 접근하는 것이므로 당연함)
	a = 1004;
	printf("%d %d %p %d\n", a, *aPtr, aPtr, b); // 1004 1004 000000A8AA99F844 12

	return 0;
}