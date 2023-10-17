#include <stdio.h>

#define ADD1(X,Y) X+Y
#define ADD2(X,Y) ((X)+(Y))
#define SQUARE1(X) X*X


#define SQUARE2(X) (X)*(X)
#define PRINT_SQR1(X) printf("The square of %d is %d.\n", X, SQUARE2(X))
#define PRINT_SQR2(X) printf("The square of " #X " is %d.\n", SQUARE2(X))

#define XNAME(N) x ## N
#define PRT_XN(N) printf("x" #N " = %d\n", x ## N);

int main(void)
{
	int sqr = SQUARE1(3);

	int a = 1;

	printf("%d\n", 2 * ADD1(1, 3)); // 2 * X + Y = 2 * 1 + 3 = 5
	printf("%d\n", 2 * ADD2(1, 3)); // 2 * ((X)+(Y)) = 2 * ((1) + (3)) = 8

	printf("%d\n", SQUARE1(1 + 2)); // 1+2*1+2 = 1 + 2 + 2 = 5
	printf("%d\n", 100 / SQUARE1(3 + 1)); // 100 / 3 + 1 * 3 + 1 = 33 + 3 + 1 = 37
	printf("%d\n", SQUARE1(++a)); // ++a * ++a = 3 * 3 = 9


	PRINT_SQR1(10);
	PRINT_SQR2(10);

	printf("\n");

	int XNAME(1) = 1; // int x1 = 1;
	int XNAME(2) = 2; // int x2 = 2;

	PRT_XN(1); // printf("x1 = %d\n", x1);
	PRT_XN(2); // printf("x2 = %d\n", x2);

	return 0;
}

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define ABS(X,Y) ((X) < 0 ? -(X) : (X))