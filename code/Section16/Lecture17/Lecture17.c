#include <stdio.h>
#include <string.h>
#include <stdarg.h> // variable argument

double Average(int num, ...);
double Average2(char* formatString, ...);

int main(void)
{
	double a, b, c, d;

	a = Average(3, 1.1, 2.2, 3.3);
	b = Average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
	c = Average2("aa", 1.1, 2.2, 3.3);
	d = Average2("aaa", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

	printf("%lf %lf\n", a, b);
	printf("%lf %lf\n", c, d);
}

double Average(int num, ...)
{
	va_list ap;
	double sum = 0.0;

	va_start(ap, num);
	for (int i = 0; i < num; ++i)
	{
		sum += va_arg(ap, double);
	}
	va_end(ap);

	return sum / num;
}

double Average2(char* formatString, ...)
{
	int num = strlen(formatString);

	va_list ap;
	double sum = 0.0;
	
	va_start(ap, formatString);
	for (int i = 0; i < num; ++i)
	{
		sum += va_arg(ap, double);
	}
	va_end(ap);

	return sum / num;
}