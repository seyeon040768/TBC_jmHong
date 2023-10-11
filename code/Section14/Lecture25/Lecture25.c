#include <stdio.h>
#include <stdlib.h>

/*int Compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
	{
		return 1;
	}
	else if (*(int*)first < *(int*)second)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int arr[] = { 8, 2, 5, 3, 6, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), Compare);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}*/

struct Kid
{
	char name[100];
	int height;
};

int Compare(const void* first, const void* second)
{
	if (((struct Kid*)first)->height > ((struct Kid*)second)->height)
	{
		return 1;
	}
	else if (((struct Kid*)first)->height < ((struct Kid*)second)->height)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(voidj)
{
	struct Kid myFriends[] = {
		"Jack Jack", 40, "Genie", 300, "Aladdin", 170, "Piona", 150
	};

	const int n = sizeof(myFriends) / sizeof(struct Kid);

	qsort(myFriends, n, sizeof(struct Kid), Compare);

	for (int i = 0; i < n; ++i)
	{
		printf("%-16s%d\n", myFriends[i].name, myFriends[i].height);
	}

	return 0;
}