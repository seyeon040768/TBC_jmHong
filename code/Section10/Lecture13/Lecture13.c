#include <stdio.h>

int main(void)
{
	/*int arr0[3] = {1, 2, 3};
	int arr1[3] = { 4, 5, 6 };

	int* parr[2] = { arr0, arr1 }; // 포인터의 배열

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			printf("%d(==%d, %d) ", parr[j][i], *(parr[j] + i), *(*(parr + j) + i));
		}
		printf("\n");
	}*/


	/*int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

	int* parr0 = arr[0];
	int* parr1 = arr[1];

	for (int i = 0; i < 3; ++i)
	{
		printf("%d ", parr0[i]); // 1 2 3
	}
	printf("\n");

	for (int i = 0; i < 3; ++i)
	{
		printf("%d ", parr1[i]); / 4 5 6
	}
	printf("\n");*/


	/*int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

	int* parr[2];
	parr[0] = arr[0];
	parr[1] = arr[1];

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			printf("%d %d %d %d\n", arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j) + i));
		}
		printf("\n");
	}

	printf("%p\n", &parr[0]); // 0000003830DCF8C8
	printf("%p\n", parr[0]); // 0000003830DCF898
	printf("%p\n", arr); // 0000003830DCF898
	printf("%p\n", &arr[0]); // 0000003830DCF898
	printf("%p\n", arr[0]); // 0000003830DCF898
	printf("%p\n", &arr[0][0]); // 0000003830DCF898*/


	char* name[] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie" };

	const int n = sizeof(name) / sizeof(char*);

	for (int i = 0; i < n; ++i)
	{
		printf("%s at %u\n", name[i], (unsigned)name[i]);
	}
	printf("\n");

	char aname[][15] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie", "Jafar" };

	const int an = sizeof(aname) / sizeof(char[15]);

	for (int i = 0; i < n; ++i)
	{
		printf("%s at %u\n", aname[i], (unsigned)aname[i]);
	}
	printf("\n");

	return 0;
}