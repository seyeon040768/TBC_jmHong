#include <stdio.h>
#include <time.h>

/*int main(void)
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
}*/


char char3[3] = { 'A', 'B', 'C' };

char(*ComplicatedFunction1())[3] // Function Returns Pointer To Char[3]
{
	return &char3;
}

typedef char(*FRPTC3())[3]; // Function Returns Pointer To Char[3]
typedef char(*(*PTFRPTC3)())[3];

char(*(*fptr1)())[3] = ComplicatedFunction1;

FRPTC3* fptr2 = ComplicatedFunction1;
PTFRPTC3 fptr3 = ComplicatedFunction1;

typedef char c3[3];

c3* ComplicatedFunction2() // Function Returns Pointer To Char[3]
{
	return &char3;
}

int main(void)
{
	char(*retVal)[3] = fptr1();

	printf("%c %c %c\n", (*retVal)[0], (*retVal)[1], (*retVal)[2]); // A B C

	c3* myC3 = fptr2();

	printf("%c %c %c\n", (*myC3)[0], (*myC3)[1], (*myC3)[2]); // A B C

	return 0;
}