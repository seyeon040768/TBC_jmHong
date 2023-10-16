#include <stdio.h>

int main(void)
{
	// International characters
	puts("�ȳ��ϼ���? �ѱ��� ����մϴ�.\n");


	// Trigraph Sequences
	int arr[3] = { 1, 2, 3 };
	printf("arr??(0??) == %d\n", arr??(0??));
	//printf("arr[0] == %d\n", arr[0]);


	// Digraphs
	printf("arr<:1:> == %d\n", arr<:1:>);
	//printf("arr[0] == %d\n", arr[0]);


	// Two physical lines vs One logical line
	printf("This is a very very very very very \
very very very long long long long long long long line.\n");


	// Tokens
	int/*a variable to count a number*/n = 1;
	//int n = 1;

	return 0;
}