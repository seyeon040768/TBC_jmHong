// unable to run in Visual C

#include <stdio.h>

#define MYTYPE(X) _Generic((X), \
	int: "int", \
	float: "float", \
	double: "double", \
	default: "other" \
)

int main(void)
{
	int d = 5;

	printf("%s\n", MYTYPE(d)); // int
	printf("%s\n", MYTYPE(2.0 * d)); // double
	printf("%s\n", MYTYPE(3L)); // other
	printf("%s\n", MYTYPE(&d)); // other

	return 0;
}