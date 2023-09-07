#include <stdio.h>

int main(void)
{
	int a = 1;
	int int_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]); // 0 1 9

	// printf("%i\n", int_arr[10000]);

	char c = 'a';
	char str1[10] = "Hello";
	char str2[10] = { 'H', 'i' };

	printf("%c\n", c); // a
	printf("%s\n", str1); // Hello
	printf("%s\n", str2); // Hi

	printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]); // 72 105 0 0 0

	// char str3[10] = "Hello, World"; // 배열 크기 부족
	char str3[20] = "Hello, \0World";
	printf("%s\n", str3); // Hello, 
	printf("%c\n", str3[9]); // o

	return 0;
}