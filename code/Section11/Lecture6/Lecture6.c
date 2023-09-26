#include <stdio.h>
#include <string.h>

void FitStr(char*, unsigned int);

char* myStrncat(char* destination, char* source, size_t count);
char* myStrcat(char* destination, char* source);
int myStrncmp(char* str1, char* str2, size_t maxCount);
int myStrcmp(char* str1, char* str2);

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


	char str1[100] = "First string";
	char str2[] = "Second string";

	myStrncat(str1, str2, 5);
	puts(str1); // First stringSecon
	myStrcat(str1, str2);
	puts(str1); // First stringSeconSecond string


	printf("%d\n", myStrncmp("Banana", "Bananas", 6)); // 0
	printf("%d\n", myStrcmp("Hello", "Hello")); // 0
	printf("%d\n", myStrcmp("A", "B")); // -1
	printf("%d\n", myStrcmp("B", "A")); // 1

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

char* myStrncat(char* destination, char* source, size_t count)
{
	int destLen = strlen(destination);
	int srcLen = strlen(source);

	if (count > srcLen)
	{
		count = srcLen;
	}

	for (int i = 0; i < count; ++i)
	{
		destination[destLen + i] = source[i];
	}

	destination[destLen + count] = '\0';

	return destination;
}

char* myStrcat(char* destination, char* source)
{
	return myStrncat(destination, source, strlen(source));
}

int myStrncmp(char* str1, char* str2, size_t maxCount)
{
	int i = 0;

	while ((str1[i] != '\0' || str2[i] != '\0') && i < maxCount)
	{
		if (str1[i] > str2[i])
		{
			return 1;
		}
		else if (str1[i] < str2[i])
		{
			return -1;
		}
		++i;
	}

	return 0;
}

int myStrcmp(char* str1, char* str2)
{
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);
	int maxLen = (str1Len > str2Len) ? str1Len : str2Len;

	return myStrncmp(str1, str2, maxLen);
}