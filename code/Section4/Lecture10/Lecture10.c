#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	// 빈칸으로 구분
	int i;
	float f;
	char str[30];
	scanf("%d %f %s", &i, &f, str); // 123 3.14 hello hi
	printf("%d %f %s", i, f, str); // 123 3.140000 hello

	char c;
	scanf("%c", &c); // (space)
	printf("%i\n", c); // 32

	unsigned i;
	scanf("%i", &i); // -123
	printf("%i\n", i); // -123

	unsigned i2;
	scanf("%u", &i2); // -123
	printf("%u\n", i2); // 4294967173

	double d = 0.0;
	scanf("lf", &d); // 123.456
	printf("%f\n", d); // 0.000000

	char str[30];
	scanf("%5s", str); // hellohi
	printf("%s\n", str); // hello

	char i;
	scanf("%hhd", &i); // 256
	printf("%i\n", i); // 0

	int i;
	scanf("%i", &i); // 123a456
	printf("%i\n", i); // 123

	// intmax_t를 쓸 때는 j 사용
	intmax_t i;
	scanf("%ji", &i); // 123
	printf("%ji", i); // 123

	int a, b;
	scanf("%d,%d", &a, &b); // 123,456
	scanf("%d ,%d", &a, &b); // 123 ,456
	scanf("%d, %d", &a, &b); // 123, 456
	scanf("%d-%d", &a, &b); // 123-456
	scanf("%dA%d", &a, &b); // 123A456
	printf("%d %d\n", a, b); // 123 456

	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b); // 123a456
	printf("%d|%c|%d", a, c, b); // 123|a|456

	// 받은 인자의 개수
	int a, b;
	int i = scanf("%d%d", &a, &b); // 123 456
	printf("%d", i); // 2

	int i;
	scanf("%*d%*d%d", &i); // 1 2 3
	printf("Your third input = %d", i); // 3

	return 0;
}