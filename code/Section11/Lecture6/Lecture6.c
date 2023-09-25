#include <stdio.h>
#include <string.h>

void FitStr(char*, unsigned int);

int main(void)
{
	/*char msg[] = "Just,"" do it!";
	puts(msg); // Just, do it!
	printf("Length %d\n", strlen(msg)); // 12
	FitStr(msg, 4);
	puts(msg); // Just
	printf("Length %d\n", strlen(msg)); // 4*/


	/*char str1[100] = "First string";
	char str2[] = "Second string";

	strcat(str1, ", ");
	strcat(str1, str2);
	strncat(str1, str2, 2);
	puts(str1); // First string, Second stringSe*/


	/*printf("%d\n", strcmp("A", "A")); // 0
	printf("%d\n", strcmp("A", "B")); // -1
	printf("%d\n", strcmp("B", "A")); // 1
	printf("%d\n", strcmp("Hello", "Hello")); // 0
	printf("%d\n", strcmp("Banana", "Bananas")); // -1
	printf("%d\n", strcmp("Bananas", "Banana")); // 1
	printf("%d\n", strncmp("Bananas", "Banana", 6)); // 0*/


	/*char dest[100] = "";
	char source[] = "Start Programming!";
	// dest = source; // Error
	// dest = "Start something"; // Error
	strcpy(dest, source);
	strncpy(dest, source, 5); // '\0' is not added
	strcpy(dest, source + 6);
	strcpy(dest, source);
	strcpy(dest + 6, "coding!");
	puts(dest); // Start coding!*/


	/*char str[100] = "";
	int i = 123;
	double d = 3.14;
	sprintf(str, " % 05d.png % f", i, d);
	puts(str);*/


	printf("%s\n", strchr("Hello, World", "W")); // (null)

	printf("%s\n", strpbrk("Hello, World", "ABCDE")); // (null)
	printf("%s\n", strpbrk("Hello, World", "abcde")); // ello, World

	printf("%s\n", strrchr("Hello, World, Hello, World", 'l')); // ld

	printf("%s\n", strstr("Hello, World", "wor")); // (null)
	printf("%s\n", strstr("Hello, World", "Wor")); // World

	return 0;
}

void FitStr(char* str, unsigned int n)
{
	if (n > strlen(str))
	{
		return;
	}

	*(str + n) = '\0';
}