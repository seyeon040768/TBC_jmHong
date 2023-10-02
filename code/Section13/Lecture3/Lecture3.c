#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(void)
{
	const UINT defaultCP = GetConsoleOutputCP();
	printf("%u\n", defaultCP);

	int ch;
	FILE* fr;
	FILE* fw;

	const char* inFilename = "원본.txt";
	const char* outFilename = "사본.txt";

	unsigned long count = 0;

	if ((fr = fopen(inFilename, "r")) == NULL)
	{
		printf("Can't open %s\n", inFilename);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(outFilename, "w")) == NULL)
	{
		printf("Can't open %s\n", outFilename);
		exit(EXIT_FAILURE);
	}

	SetConsoleOutputCP(CP_UTF8);

	while ((ch = fgetc(fr)) != EOF) // getc(fr)
	{
		//putc(ch, stdout); // same as putchar(ch);
		fputc(ch, stdout);

		fputc(ch, fw);

		++count;
	}

	fclose(fr);
	fclose(fw);

	SetConsoleOutputCP(defaultCP);

	printf("FILE %s has %lu characters\n", inFilename, count);
	printf("Copied to %s\n", outFilename);

	printf("한글 출력 확인\n");

	return 0;
}