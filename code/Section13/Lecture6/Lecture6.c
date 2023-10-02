#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch;
	long cur;

	FILE* fp = fopen("test.txt", "r");

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur); // ftell() = 0

	fseek(fp, 2L, SEEK_SET);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur); // ftell() = 2
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch); // 67 C
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur); // ftell() = 3

	fseek(fp, -2L, SEEK_CUR);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur); // ftell() = 1
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch); // 66 B

	fseek(fp, 0L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch); // -1 \0

	fseek(fp, -1L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch); // 90 Z

	fseek(fp, -2L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch); // 89 Y


	fpos_t pt;
	pt = 10;
	fsetpos(fp, &pt);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch); // 75 K
	fgetpos(fp, &pt);
	printf("%lld\n", pt); // 11

	return 0;
}