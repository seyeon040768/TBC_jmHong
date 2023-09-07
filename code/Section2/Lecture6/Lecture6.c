#include <stdio.h>

int main(void)
{
	int x, y, z;

	x = 1;
	y = 4;

	z = x + y;

	printf("%i + %i = %i", x, y, z);

	float salary;
	printf("$______\b\b\b\b\b\b"); // $______ (커서 $ 바로 다음에 위치)
	scanf("%f", &salary);

	printf("AB\tCDEF\n"); // AB      CDEF
	printf("ABC\tDEF\n"); //ABC     DEF

	printf("\\ \'HA+\' \"Hello\" \?\n"); // \ 'HA+' "Hello" ?

	return 0;
}