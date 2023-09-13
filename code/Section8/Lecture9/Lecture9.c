#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c;
	FILE* file = NULL;
	char file_name[] = "my_file.txt"; // 비주얼 스튜디오 실행: 프로젝트 폴더, exe 파일 실행: exe 파일 경로

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