#include <stdio.h>

int main(void)
{
	// Lecture3.exe > output.txt
	// Lecture3.exe >> output.txt
	// Lecture3.exe < input.txt
	// test.exe | Lecture3.exe
	

	//printf("programming.\n");

	char str[100];
	scanf("%s", str);
	printf("I love %s\n", str);

	return 0;
}