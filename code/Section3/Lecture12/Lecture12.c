#include <stdio.h>
#include <math.h>

int main(void)
{
	// round-off errors
	float a, b;
	a = 1.0E20f + 1.0f;
	b = a - 1.0E20f;
	printf("%f\n", b); // 0.000000

	float c = 0.0f;
	for (int i = 0; i < 100; i++)
	{
		c += 0.01f;
	}
	printf("%f\n", c); // 0.999999

	// overflow
	float max = 3.402823466e+38F;
	printf("%f\n", max); // 340282346638528859811704183484516925440.000000
	max = max * 100.0f;
	printf("%f\n", max); // inf

	// underflow
	float d = 1.401298464e-45F;
	printf("%e\n", d); // 1.401298e-45
	d = d / 2.0f;
	printf("%e\n", d); // 0.000000e+00

	float e = 104.0f;
	printf("%f\n", e); // 104.000000
	e = e / 0.0f;
	printf("%f\n", e); // inf

	float f = asinf(1.0f);
	printf("%f\n", f); // 1.570796

	f = asinf(2.0f);
	printf("%f\n", f); // -nan(ind)

	return 0;
}