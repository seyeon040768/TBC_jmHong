#include <stdio.h>

int main(void)
{
	float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

	printf("%lld\n", (long long)arr2d);
	printf("%lld\n", (long long)arr2d[0]);

	printf("%lld\n", (long long)*arr2d[0]);
	printf("%lld\n", (long long)&arr2d[0]);
	printf("%lld\n", (long long)&arr2d[0][0]);
	printf("%f %f\n", arr2d[0][0], **arr2d);
	printf("\n");

	printf("%lld\n", (long long)(arr2d + 1));
	printf("%lld\n", (long long)(&arr2d[1]));
	printf("%lld\n", (long long)(arr2d[1]));
	printf("%lld\n", (long long)(*(arr2d + 1)));
	printf("%lld\n", (long long)(&arr2d[0] + 1));
	printf("%lld\n", (long long)(&arr2d[1][0]));
	printf("\n");

	printf("%f\n", *(*(arr2d + 1) + 2));
	printf("\n");

	for (int j = 0; j < 2; ++j)
	{
		printf("[%d] = %lld, %lld\n", j, (long long)(arr2d[j]), (long long)*(arr2d + j));

		for (int i = 0; i < 4; ++i)
		{
			printf("[%d][%d] = %f, %f\n", j, i, arr2d[j][i], *(*(arr2d + j) + i));

			*(*(arr2d + j) + i) += 1.0f; // arr2d[j][i] += 1.0f;
		}
	}
	printf("\n");


	//float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

	//float(*pa)[4]; // 4개의 실수를 가진 배열에 대한 포인터
	//float* ap[2]; // 크기가 2인 실수형 포인터 배열

	//printf("%zu\n", sizeof(pa)); // x86: 4, x64: 8
	//printf("%zu\n", sizeof(ap)); // x86: 8, x64: 16
	//printf("\n");

	//pa = arr2d;
	//// pa[0] = arr2d[0]; // Error
	//// pa[1] = arr2d[1]; // Error
	//
	//// ap = arr2d; // Error
	//ap[0] = arr2d[0];
	//ap[1] = arr2d[1];

	//printf("%lld %lld\n", (long long)pa, (long long)(pa + 1));
	//printf("%lld %lld\n", (long long)arr2d[0], (long long)arr2d[1]);
	//printf("%lld %lld\n", (long long)pa[0], (long long)(pa[0] + 1));
	//printf("%f\n", pa[0][0]);
	//printf("%f\n", *pa[0]);
	//printf("%f\n", **pa);
	//printf("%f\n", pa[1][3]);
	//printf("%f\n", *(*(pa + 1) + 3));
	//printf("\n");

	//printf("%lld %lld\n", (long long)ap, (long long)(ap + 1));
	//printf("%lld %lld\n", (long long)arr2d[0], (long long)arr2d[1]);
	//printf("%lld %lld\n", (long long)ap[0], (long long)(ap[0] + 1));
	//printf("%f\n", ap[0][0]);
	//printf("%f\n", *ap[0]);
	//printf("%f\n", **ap);
	//printf("%f\n", ap[1][3]);
	//printf("%f\n", *(*(ap + 1) + 3));
	//printf("\n");

	return 0;
}