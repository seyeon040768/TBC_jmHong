// unable to run in VSC

#include <stdio.h>
#include <stdalign.h>

int main(void)
{
#ifdef __clang_major__
	printf("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
#endif

#ifdef __GNUC__
	printf("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif

	printf("Alignment of char = %zu\n", alignof(char));
	printf("alignof(float[10]) = %zu\n", alignof(float[10]));
	printf("alignof(struct {char c; int n;}) = %zu\n",
		alignof(struct { char c; int n; }));

	double dx;
	char ca;
	char cx;
	double dz;
	char cb;
	//char _Alignas(double) cz;
	//char alignas(16) cz;
	char cz;

	//printf("char alignment: %zd\n", _Alignof(char));
	//printf("double alignment: %zd\n", _Alignof(double));
	printf("char alignment: %zd\n", alignof(char));
	printf("double alignment: %zd\n", alignof(double));

	printf("&dx: %p %llu\n", &dx, (unsigned long long)& dx % 8);
	printf("&ca: %p %llu\n", &ca, (unsigned long long)& ca % 8);
	printf("&cx: %p %llu\n", &cx, (unsigned long long)& cx % 8);
	printf("&dz: %p %llu\n", &dz, (unsigned long long)& dz % 8);
	printf("&cb: %p %llu\n", &cb, (unsigned long long)& cb % 8);
	printf("&cz: %p %llu\n", &cz, (unsigned long long)& cz % 8);

	unsigned char alignas(long double) c_arr[sizeof(long double)];

	return 0;
}