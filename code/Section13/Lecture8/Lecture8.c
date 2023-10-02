#include <stdio.h>
#include <Windows.h>

int main(void)
{
	FILE* fp = fopen("test.txt", "rb");

	unsigned char ch;

	SetConsoleOutputCP(CP_UTF8);

	while (fread(&ch, sizeof(unsigned char), 1, fp) > 0)
	{
		printf("%hhu %c\n", ch, ch);
	}

	fclose(fp);

	return 0;
}