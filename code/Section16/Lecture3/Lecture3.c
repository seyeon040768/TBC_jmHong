#include <stdio.h>

/*
#define			SAY_HELLO		printf("Hello, World!");
Preprocesssor	Macro (name)	body (or replacement list)

Macro expansion
*/

/*
#define ONE 1
#define SQUARE(X) X*X
*/

#define PI 3.141592 // Symbolic Constants
#define GRAVITY 9.8

#define THREE 3
#define MESSAGE "The greatest glory int living lies not in never falling, \
but in rising every time we fall."

#define NINE THREE*THREE
#define SAY_HELLO printf("Hello, World!\n");
#define FORMAT "Number is %d.\n"

#define MY_CH 'Z'
#define MY_ST "Z" // Z\0

#define LIMIT 20
const int LIM = 50;
static int arr1[LIMIT];
const int LIM2 = 2 * LIMIT;

 /*
 Tokens

 #define SIX 3*2
 #define SIX 3 * 2
 #define SIX 3       *       2
 */

// Redefining Constants
#define SIX 2*3
#define SIX 2*3
//#define SIX 2 * 3 // Warning (Token 단위로 봤을 때 다름)
#undef SIX

int main(void)
{
	int n = THREE;

	SAY_HELLO;
	n = NINE;

	printf(FORMAT, n);
	printf("%s\n", MESSAGE);
	printf("SAY_HELLO NINE\n"); // Not replaced

	return 0;
}