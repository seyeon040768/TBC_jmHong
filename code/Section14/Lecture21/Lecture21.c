#include <stdio.h>

void F1(void)
{
	return;
}

int F2(char i)
{
	return i + 1;
}

int main(void)
{
	void (*pF1)() = F1;
	//void (*pF1)() = &F1;

	int (*pF2)(char) = F2;

	(*pF1)();
	//pF1();

	int a = pF2('A');
	//int a = (*pF2)('A');

	printf("%d\n", a); // 66

	return 0;
}