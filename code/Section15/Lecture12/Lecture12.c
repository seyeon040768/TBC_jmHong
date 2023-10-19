// unable to run in Visual C

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

	printf("Alignment of char = %zu\n", alignof(char)); // 1
	printf("alignof(float[10]) = %zu\n", alignof(float[10])); // 4
	printf("alignof(struct {char c; int n;}) = %zu\n",
		alignof(struct { char c; int n; })); // 4

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
	printf("char alignment: %zd\n", alignof(char)); // 1
	printf("double alignment: %zd\n", alignof(double)); // 8

	printf("&dx: %p %llu\n", &dx, (unsigned long long) & dx % 8); // &dx: 0x7ffd16882860 0
	printf("&ca: %p %llu\n", &ca, (unsigned long long) & ca % 8); // &ca: 0x7ffd1688285c 4
	printf("&cx: %p %llu\n", &cx, (unsigned long long) & cx % 8); // &cx: 0x7ffd1688285d 5
	printf("&dz: %p %llu\n", &dz, (unsigned long long) & dz % 8); // &dz: 0x7ffd16882868 0
	printf("&cb: %p %llu\n", &cb, (unsigned long long) & cb % 8); // &cb: 0x7ffd1688285e 6
	printf("&cz: %p %llu\n", &cz, (unsigned long long) & cz % 8); // &cz: 0x7ffd1688285f 7

	unsigned char alignas(long double) c_arr[sizeof(long double)];

	return 0;
}