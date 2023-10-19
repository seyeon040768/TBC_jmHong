#include <stdio.h>

/*
#pragra tokens (ex: once)
*/

//#pragma pack(1) // padding 1byte
//_Pragma("pack(1)")
/*#define PACK1 _Pragma("Pack(1)")
PACK1*/

//#pragma warning( disable : 4477 )
//#pragma warning( error : 4477 )

struct S
{
	int i;
	char ch;
	double d;
};

int main(void)
{
	struct S a;
	printf("Size of a is: %zd", sizeof(a)); // 16 or 13(#pragma pack(1))
	printf("Size of a is: %d", sizeof(a)); // warning 4477

	return 0;
}