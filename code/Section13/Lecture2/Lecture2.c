#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ch;
	FILE* fr;
	FILE* fw;

	const char* outFilename = "output.txt";

	unsigned long count = 0;

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(outFilename, "w")) == NULL)
	{
		printf("Can't open %s\n", outFilename);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fr)) != EOF) // getc(fr)
	{
		//putc(ch, stdout); // same as putchar(ch);
		fputc(ch, stdout);

		fputc(ch, fw);

		++count;
	}

	fclose(fr);
	fclose(fw);

	printf("FILE %s has %lu characters\n", argv[1], count);

	return 0;
}