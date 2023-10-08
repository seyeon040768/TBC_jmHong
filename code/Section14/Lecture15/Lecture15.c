#include <stdio.h>

int main(void)
{
	union MyUnion {
		int i;
		double d;
		char c;
	};

	union MyUnion uni;

	printf("%zd\n", sizeof(union MyUnion)); // 8
	printf("%llu\n", (unsigned long long)& uni); // 435732608040
	printf("%llu %llu %llu\n", // 435732608040 435732608040 435732608040
		(unsigned long long)& uni.i, (unsigned long long)& uni.d, (unsigned long long)& uni.c);

	union MyUnion uni1;

	uni1.c = 'A';
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i); // A 41 -858993599
	// 0xCCCCCC41 = -858993599

	uni1.i = 0;
	uni1.c = 'A';
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i); // A 41 65
	// 0x00000041 = 65

	uni1.d = 1.2;
	printf("%d %f %d %d\n", uni1.i, uni1.d, (int)uni1.c, uni1.c); // 858993459 1.200000 51 51
	// 0x3ff3333333333333 = 1.9999999...
	// 0x33333333 = 858993459
	// 0x33 = 51


	union MyUnion uni2 = uni1;
	union MyUnion uni3 = { 10 }; // First member only
	union MyUnion uni4 = { .c = 'A' };
	union MyUnion uni5 = { .d = 1.23, .i = 100 }; // Not recommended

	printf("%d %f %c\n", uni5.i, uni5.d, uni5.c); // 100 0.000000 d

	uni.i = 123;
	uni.d = 1.2;
	uni.c = 'k';

	printf("%d %f %c\n", uni.i, uni.d, uni.c); // 858993515 1.200000 k

	union MyUnion* pu = &uni;
	int x = pu->i;

	uni.c = 'A';
	double real = 3.14 * uni.d; // ?? uni.d value is weird

	return 0;
}