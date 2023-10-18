#include <stdio.h>

#include "DifferentFile.h"

void DifferentFunction();

int main(void)
{
	printf("__FILE__: %s\n", __FILE__);
	printf("__DATE__: %s\n", __DATE__);
	printf("__TIME__: %s\n", __TIME__);
	printf("__LINE__: %d\n", __LINE__);
	printf("__func__: %s\n", __func__);

	DifferentFunction();

	DifferentFuncInDifferentFile();

//#line 7
//	printf("__LINE__ after #line %d\n", __LINE__); // 7
//
//#line 1 "hello.txt"
//	printf("__LINE__ after #line %d\n", __LINE__); // 8
//	printf("__FILE__: %s\n", __FILE__);

#if __LINE__ != 26
#error Not line 33
#endif

	return 0;
}

void DifferentFunction()
{
	printf("This function is %s\n", __func__); // This function is DifferentFunction
	printf("This is line %d\n", __LINE__); // This is line 25
}