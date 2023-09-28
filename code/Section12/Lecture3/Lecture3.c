#include <stdio.h>

/* File Scope
int a = 123;
int b;

void func1()
{
	++a;
}

void func2()
{
	a += 2;
}

int main(void)
{
	int local = 1234;

	func1();
	func2();

	printf("%d\n", a); // 126
	printf("%d\n", b); // 0
	printf("%d\n", local); // 1234

	return 0;
}*/


/* Scope
void F1(int hello, double world);

double FuncBlock(double d)
{
	double p = 0.0;

	int i;
	for (i = 0; i < 10; ++i)
	{
		double q = d * i;
		p *= q;

		if (i == 5)
		{
			goto hello;
		}
	}

hello:
	printf("Hello, World\n");

	return p;
}

int main(void)
{
	FuncBlock(1.0);

	return 0;
}

void F1(int block, double world)
{

}*/

/*
// Main.c
int el; // file scope with external linkage
static int il; // file scope with internal linkage

void TestLinkage();

int main(void)
{
	el = 1024;

	TestLinkage();

	printf("%d\n", el); // 1025

	return 0;
}

// Second.c
extern int el;
// extern int il;

void TestLinkage()
{
	printf("DoSomething called\n");
	printf("%d\n", el); // 1024

	++el;
}*/


void Count()
{
	int ct = 0;
	printf("count = %d\n", ct);
	++ct;
}

void StaticCount()
{
	static int ct = 0;
	printf("static count = %d\n", ct);
	++ct;
}

int main(void)
{
	Count(); // 0
	Count(); // 0
	StaticCount(); // 0
	StaticCount(); // 1

	return 0;
}