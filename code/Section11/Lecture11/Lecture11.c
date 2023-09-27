#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	/*if (argc < 3)
	{
		printf("Wrong Usage of %s\n", argv[0]);
		return 0;
	}

	int times = atoi(argv[1]);

	//for (int i = 0; i < times; ++i)
	//{
	//	puts(argv[2]);
	//}

	printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
	*/


	/*char str1[] = "-1024Hello";
	char* end;
	long l = strtol(str1, &end, 10);
	printf("%s %ld %s %d\n", str1, l, end, (int)*end); // -1024Hello -1024 Hello 72*/

	/*char str2[] = "10FFHello";
	char* end;
	long l = strtol(str2, &end, 16);
	printf("%s %ld %s %d\n", str2, l, end, (int)*end); // 10FFHello 4351 Hello 72*/


	char temp[100];
	puts(_itoa(10, temp, 16)); // a

	sprintf(temp, "%x", 10); // a
	puts(temp);

	return 0;
}