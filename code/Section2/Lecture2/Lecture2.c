#include <stdio.h> //��ó���� (preprocessor), ������ ���� ����

int main(void) // main �Լ� ���� ����
{ // ����(scope)�� ����
	int a;
	int b; // ���� ����
	int c;

	a = 1; // ������ �� ����
	b = 2;
	c = a + b; // ������ ���� ��� ����

	printf("Result is %i", c); // �Լ� ȣ��

	return 0; // ��� ���� ��ȯ
} // ����(scope)�� ��