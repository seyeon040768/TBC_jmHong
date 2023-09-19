#include <stdio.h>

int main(void)
{
	int* ptr = 0;
	// printf("%d", *ptr); // Error in this lecture

	printf("%p %lld\n", ptr, (long long)ptr); // 0000000000000000 0

	++ptr;

	printf("%p %lld\n", ptr, (long long)ptr); // 0000000000000004 4

	// ptr = -ptr; // Not working
	// ptr = +ptr; // Not working

	
	int arr[10];
	int* ptr1 = &arr[3], * ptr2 = &arr[5];

	// ptr2 = ptr1 + ptr2; // Not working
	int i = ptr2 - ptr1;

	printf("%p %p %d\n", ptr1, ptr2, i); // 0000001EADCFFA84 0000001EADCFFA8C 2

	return 0;
}