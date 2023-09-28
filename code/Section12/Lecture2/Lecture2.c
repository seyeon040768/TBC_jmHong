#include <stdio.h>

int main(void)
{
	int varName = 3; // creates an object called "varName"
	int* pt = &varName; // pt is an identifier
	*pt = 1; // *pt is not an identifier

	int arr[100]; // arr is an identifier, not object
	arr[0] = 7; // arr[0] is an object


	varName = 3; // modifiable lvalue

	pt = &varName;
	int* ptr = arr;
	*pt = 7; // *pt is an modifiable lvalue expression

	int* ptr2 = arr + 2 * varName; // address rvalue
	*(arr + 2 * varName) = 456; // lvalue expression

	const char* str = "Constant string"; // str is a modifiable lvalue
	str = "Second string";
	// str[0] = 'A'; // Error

	char str2[] = "String in an array";
	str2[0] = 'A';

	return 0;
}