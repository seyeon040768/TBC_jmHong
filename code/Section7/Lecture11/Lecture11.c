#include <stdio.h>
#include <float.h>

int main(void)
{
	float input;
	float min = FLT_MAX;
	float max = -FLT_MAX;
	float sum = 0.0f;

	int count = 0;

	while (scanf("%f", &input) == 1)
	{
		if (input < 0.0f || input > 100.0f)
		{
			continue;
		}

		if (input < min)
		{
			min = input;
		}

		if (input > max)
		{
			max = input;
		}

		sum += input;

		++count;
	}

	printf("min = %f, max = %f, ave = %f\n", min, max, sum / (float)count);

	return 0;
}