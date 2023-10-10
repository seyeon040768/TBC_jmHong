#include <stdio.h>
#include <time.h>

int main(void)
{
	typedef unsigned char BYTE;

	BYTE x;
	BYTE y[10] = { 0, };
	BYTE* z = &x;

	{
		typedef unsigned char byte; // you can use lowercases

		size_t s = sizeof(byte); // size_t x86: unsigned int, x64: unsigned long long
	}

	//byte b; // typedef definition has a scope


	time_t t = time(NULL);

	printf("%lld\n", t);


	// typedef vs #define
	typedef char* STRING;

	STRING name = "John Wick", sign = "World";	

	// #define STRING char *
	// STRING name, sign; // char * name, sign;
	// sign is not char*


	typedef struct Complex
	{
		float real;
		float imag;
	} COMPLEX;

	typedef struct { double width; double height; } Rect;
	Rect r1 = { 1.1, 2.2 };
	Rect r2 = r1;
	printf("%f %f\n", r2.width, r2.height);

	return 0;
}