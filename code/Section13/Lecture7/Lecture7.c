#include <stdio.h>

int main(void)
{
	FILE* fp;
	int ch;

	fp = fopen("input.txt", "r");

	ch = fgetc(fp);
	fputc(ch, stdout); // "

	ungetc(ch, fp);

	ch = fgetc(fp);
	fputc(ch, stdout); // "

	fclose(fp);

	printf("\n");


	fp = fopen("input.txt", "r");

	char buffer[32] = { '\0', };

	setvbuf(fp, buffer, _IOFBF, sizeof(buffer));

	ch = fgetc(fp);

	for (int i = 0; i < sizeof(buffer); ++i)
	{
		printf("%c", buffer[i]); // "I choose a lazy person to do a
	}
	printf("\n");

	fclose(fp);


	// fflush(fp);

	return 0;
}