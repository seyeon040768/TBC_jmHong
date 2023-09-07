#include <stdio.h>

void say_hello(void);

int main(void)
{
	say_hello();
	say_hello();
	say_hello();
	say_hello();
	say_hello();

	return 0;
}

void say_hello(void)
{
	printf("Hello, World!\n");
}