#include <stdio.h>

int main(void)
{
	// promotion in assignments
	short s = 64;
	int i = s;

	float f = 3.14f;
	double d = f;

	// demotion in assignemnts
	d = 1.25;
	f = 1.25;
	f = 1.123;

	// double로 변환 후 대입
	d = f + 1.234;
	f = f + 1.234;

	// casting operators
	d = (double)3.14f;
	i = 1.6 + 1.7; // 3
	i = (int)1.6 + (int)1.7; // 2

	char c;
	f = i = c = 'A';
	printf("%c %d %f\n", c, i, f); // A 65 65.000000
	c = c + 2;
	i = f + 2 * c;
	printf("%c %d %f\n", c, i, f); // C 199 65.000000
	c = 1106;
	printf("%c\n", c); // R(82)
	c = 83.99;
	printf("%c\n", c); // S(83)

	return 0;
}