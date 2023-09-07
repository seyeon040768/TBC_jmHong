#include <stdio.h>

int main(void)
{
	/*const double speed = 1.0;
	const unsigned repeat_max = 10;

	double dt = 1.0;
	double time = 0.0;
	double dist = 0.0;

	for (unsigned i = 0; i < repeat_max; ++i)
	{
		dist += speed * dt;
		time += dt;

		printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);

		dt *= 0.5; // 곱하기가 나누기보다 빠름
	}*/

	const double speed = 1.0;
	const unsigned repeat_max = 50;

	double time = 0.0;
	double dist_arch = 0.0;
	double dist_turtle = 1.0;
	double speed_arch = 10.0;
	double speed_turtle = 0.001;
	double dt = 0.01;

	printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fn\n",
		time, dt, dist_arch, dist_turtle);

	for (unsigned i = 0; i < repeat_max; ++i)
	{
		dist_arch += speed_arch * dt;
		dist_turtle += speed_turtle * dt;
		time += dt;

		printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fn\n",
			time, dt, dist_arch, dist_turtle);

		dt *= 0.5;
	}

	return 0;
}