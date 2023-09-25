#include <stdio.h>

#define TEST "A string from #define."

void CustomPut(const char* str);
int CustomPut2(const char* str);

int main(void)
{
	/*char str[60] = "String array initialized";
	const char* ptr = "A pointer initialized";

	puts("String without \\n");
	puts("END");
	puts(TEST);
	puts(TEST + 5);
	puts(&str[3]);
	// puts(str[3]); // Error
	puts(ptr + 3);*/


	/*char str[] = {'H', 'I', '!'};
	puts(str); // Warning C6054 String 'str' might not be zero - terminated*/


	/*char line[100];
	while(gets(line))
	{
		puts(line);
	}*/


	/*char line[100];
	while (fgets(line, 100, stdin))
	{
		fputs(line, stdout);
	}*/


	/*char str[] = "Just do it, do it!";
	printf("%s\n", str);
	puts(str);*/


	/*char input[100] = "";
	int ret = scanf("%10s", input); // Input: Just do it, do it!
	printf("%s\n", input); // Just
	ret = scanf("%10s", input); // 버퍼에 아직 남아 있는 값을 읽음
	printf("%s\n", input); // do*/


	CustomPut("Just ");
	CustomPut("Do it!");

	printf("%d\n", CustomPut2("12345"));

	return 0;
}

void CustomPut(const char* str)
{
	while (*str != '\0')
	{
		putchar(*str);
		++str;
	}
}

int CustomPut2(const char* str)
{
	const char* start = str;

	while (*str != '\0')
	{
		putchar(*str);
		++str;
	}
	putchar('\n');

	return str - start;
}