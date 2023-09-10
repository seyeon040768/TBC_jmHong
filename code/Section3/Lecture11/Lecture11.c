#include <stdio.h>

int main(void)
{
	printf("%u\n", sizeof(float)); // 4
	printf("%u\n", sizeof(double)); // 8
	printf("%u\n", sizeof(long double)); // �����Ϸ� ���� �ٸ�(double�� ���ų� �� ��Ȯ��)

	float f = 123.456f;
	double d = 123.456;

	float f2 = 123.456; // double�� float�� ������ �ϸ� ��� �߻�
	double d2 = 123.456f;

	int i = 3;
	float f3 = 3.f; // 3.0f
	double d3 = 3.; // 3.0

	float f4 = 1.234e10f;

	float f5 = 0x1.1p1; // p�� 10������ e�� ����, px�� 2�� x����
	double d5 = 1.0625e0;

	printf("%f %F %e %E\n", f, f, f, f); // 123.456001 123.456001 1.234560e+02 1.234560E+02
	printf("%f %F %e %E\n", d, d, d, d); // 123.456000 123.456000 1.234560e+02 1.234560E+02
	printf("%a %A\n", f5, f5); // 0x1.1000000000000p+1 0X1.1000000000000P+1
	printf("%a %A\n", d5, d5); // 0x1.1000000000000p+0 0X1.1000000000000P+0

	return 0;
}