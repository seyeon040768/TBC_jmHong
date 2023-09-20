#include <stdio.h>

int main(void)
{
	int arr[5] = { 100, 200, 300, 400, 500 };
	int* ptr1, * ptr2, * ptr3;

	ptr1 = arr; // Assignment

	printf("%p %d %p\n", ptr1, *ptr1, &ptr1); // dereferencing

	ptr2 = &arr[2]; // Address-of operator &

	printf("%p %d %p\n", ptr2, *ptr2, &ptr2);

	ptr3 = ptr1 + 4; // Adding an integer from a pointer

	printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

	// Differencing
	printf("%td\n", ptr3 - ptr1); // t is for pointer difference

	ptr3 -= 4;

	printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

	ptr1++;
	ptr1--;
	--ptr1;
	++ptr1;

	if (ptr1 == ptr3)
	{
		printf("Same\n");
	}
	else
	{
		printf("Different\n");
	}


	double d = 3.14;
	double* ptrD = &d;

	if (ptr1 == ptrD) // warning C4133: '==': incompatible types - from 'double *' to 'int *'
	{
		printf("Same\n");
	}
	else
	{
		printf("Different\n");
	}

	return 0;
}