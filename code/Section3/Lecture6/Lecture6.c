#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void)
{
	unsigned int u_max = UINT_MAX + 1;

	// ������ ���ڷ� ǥ��
	char buffer[33];
	_itoa(u_max, buffer, 2);

	printf("decimal: %u\n", u_max);	// decimal: 0
	printf("binary: %s\n", buffer);	// binary: 0

	return 0;
}