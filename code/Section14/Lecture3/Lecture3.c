#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	struct Aligned
	{
		int a;
		float b;
		double c;
	};

	/*
	* |0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
	* |int a  |float b|double c             |
	*/

	struct Aligned a1, a2;

	printf("struct Aligned a1\n");
	printf("Sizeof %zd\n", sizeof(struct Aligned)); // 16
	printf("%llu\n", (unsigned long long)& a1); // 406228237224
	printf("%llu\n", (unsigned long long)& a1.a); // 406228237224
	printf("%llu\n", (unsigned long long)& a1.b); // 406228237228
	printf("%llu\n", (unsigned long long)& a1.c); // 406228237232

	printf("struct Aligned a2\n");
	printf("Sizeof %zd\n", sizeof(a2)); // 16
	printf("%llu\n", (unsigned long long)& a2); // 406228237272
	printf("%llu\n", (unsigned long long)& a2.a); // 406228237272
	printf("%llu\n", (unsigned long long)& a2.b); // 406228237276
	printf("%llu\n", (unsigned long long)& a2.c); // 406228237280


	struct Padded1
	{
		char a;
		float b;
		double c;
	};

	/*
	* |0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
	* |char a |float b|double c             |
	*/

	struct Padded1 p1;

	printf("\nstruct Padded1 p1\n");
	printf("Sizeof %zd\n", sizeof(p1)); // 16
	printf("%llu\n", (unsigned long long)& p1); // 406228237320
	printf("%llu\n", (unsigned long long)& p1.a); // 406228237320
	printf("%llu\n", (unsigned long long)& p1.b); // 406228237324
	printf("%llu\n", (unsigned long long)& p1.c); // 406228237328

	struct Padded2
	{
		float a;
		double b;
		char c;
	};

	/*
	* |0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|
	* |float a        |double b             |char c                 |
	*/

	struct Padded2 p2;

	printf("\nstruct Padded2 p2\n");
	printf("Sizeof %zd\n", sizeof(p2)); // 24
	printf("%llu\n", (unsigned long long)& p2); // 406228237368
	printf("%llu\n", (unsigned long long)& p2.a); // 406228237368
	printf("%llu\n", (unsigned long long)& p2.b); // 406228237376
	printf("%llu\n", (unsigned long long)& p2.c); // 406228237384

	struct Padded3
	{
		char a;
		double b;
		double c;
	};

	struct Padded3 p3;

	printf("\nstruct Padded3 p3\n");
	printf("Sizeof %zd\n", sizeof(p3)); // 24
	printf("%llu\n", (unsigned long long)& p3); // 406228237416
	printf("%llu\n", (unsigned long long)& p3.a); // 406228237416
	printf("%llu\n", (unsigned long long)& p3.b); // 406228237424
	printf("%llu\n", (unsigned long long)& p3.c); // 406228237424


	struct Person
	{
		char name[41];
		int age;
		float height;
	};

	struct Person mom;

	printf("\nstruct Person mom\n");
	printf("Sizeof %zd\n", sizeof(mom)); // 52
	printf("%llu\n", (unsigned long long)& mom.name[0]); // 406228237464
	printf("%llu\n", (unsigned long long)& mom.age); // 406228237508
	printf("%llu\n", (unsigned long long)& mom.height); // 406228237512

	return 0;
}