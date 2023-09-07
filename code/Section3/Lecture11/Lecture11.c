#include <stdio.h>

int main(void)
{
	printf("%u\n", sizeof(float)); // 4
	printf("%u\n", sizeof(double)); // 8
	printf("%u\n", sizeof(long double)); // 컴파일러 마다 다름(double과 같거나 더 정확함)

	float f = 123.456f;
	double d = 123.456;

	float f2 = 123.456; // double을 float에 넣으려 하면 경고 발생
	double d2 = 123.456f;

	int i = 3;
	float f3 = 3.f; // 3.0f
	double d3 = 3.; // 3.0

	float f4 = 1.234e10f;

	float f5 = 0x1.1p1; // p는 10진수의 e와 같음, px는 2의 x제곱
	double d5 = 1.0625e0;

	printf("%f %F %e %E\n", f, f, f, f); // 123.456001 123.456001 1.234560e+02 1.234560E+02
	printf("%f %F %e %E\n", d, d, d, d); // 123.456000 123.456000 1.234560e+02 1.234560E+02
	printf("%a %A\n", f5, f5); // 0x1.1000000000000p+1 0X1.1000000000000P+1
	printf("%a %A\n", d5, d5); // 0x1.1000000000000p+0 0X1.1000000000000P+0

	return 0;
}