#include <stdio.h>

#define LIMIT 400
#undef LIMIT


#include "HeaderB.h"
#include "HeaderA.h"


#define TYPE 1

#if TYPE == 1
#include "MyFunction1.h"
#elif TYPE == 2
#include "MyFunction2.h"
#else
static void MyFunction()
{
	printf("Wrong compile option!\n");
}
#endif


#define REPORT

int Sum(int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; ++k)
	{
		s += k;

#ifdef REPORT
		printf("%d %d\n", s, k);
#endif
	}

	return s;
}


void SayHello()
{
//#ifdef _WIN64
#if defined (_WIN64)
	printf("Hello, WIN64\n");
#elif _WIN32
	printf("Hello, WIN32\n");
#elif __linux__
	printf("Hello, linux\n");
#endif
}

int main(void)
{
	// printf("%d\n", LIMIT); // Error

	TestFunctionA();
	TestFunctionB();

	MyFunction(); // MyFunction1.h

	printf("\n%d \n", Sum(1, 10));

	SayHello();

	return 0;
}