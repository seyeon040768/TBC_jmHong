#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c;
	FILE* file = NULL;
	char file_name[] = "my_file.txt"; // ���־� ��Ʃ��� ����: ������Ʈ ����, exe ���� ����: exe ���� ���

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		printf("Failed to open file.\n");
		// return 1;
		exit(1);
	}

	while ((c = getc(file)) != EOF)
	{
		putchar(c);
	}
	
	fclose(file);

	return 0;
}