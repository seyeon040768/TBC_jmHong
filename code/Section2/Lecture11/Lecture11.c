#include <stdio.h>

int main(void)
{
	int n1, n2, n3, n4;	// n의 1, 2, 3, 4 제곱

	n5 = 1; // 문법 오류

	n1 = 1;
	n2 = n1 * n1;
	n3 = n2 * n1;
	n4 = n2 * n1;	// 문맥 오류

	return 0;
}