#include <stdio.h>

int main(void)
{
	/*float arr2d[2][4] = {{1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f}};

	printf("%lld\n", (long long)arr2d); // 414436226936
	printf("%lld\n", (long long)arr2d[0]); // 414436226936

	printf("%lld\n", (long long)*arr2d[0]); // 1
	printf("%lld\n", (long long)&arr2d[0]); // 414436226936
	printf("%lld\n", (long long)&arr2d[0][0]); // 414436226936
	printf("%f %f\n", arr2d[0][0], **arr2d); // 1.000000 1.000000
	printf("\n");

	printf("%lld\n", (long long)(arr2d + 1)); // 414436226952
	printf("%lld\n", (long long)(&arr2d[1])); // 414436226952
	printf("%lld\n", (long long)(arr2d[1])); // 414436226952
	printf("%lld\n", (long long)(*(arr2d + 1))); // 414436226952
	printf("%lld\n", (long long)(&arr2d[0] + 1)); // 414436226952
	printf("%lld\n", (long long)(&arr2d[1][0])); // 414436226952
	printf("\n");

	printf("%f\n", *(*(arr2d + 1) + 2)); // 7.000000
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
	printf("\n");*/


	float arr2d[2][4] = {{1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f}};

	float(*pa)[4]; // 4개의 실수를 가진 배열에 대한 포인터
	float* ap[2]; // 크기가 2인 실수형 포인터 배열

	printf("%zu\n", sizeof(pa)); // x86: 4, x64: 8
	printf("%zu\n", sizeof(ap)); // x86: 8, x64: 16
	printf("\n");

	pa = arr2d;
	// pa[0] = arr2d[0]; // error
	// pa[1] = arr2d[1]; // error

	// ap = arr2d; // error
	ap[0] = arr2d[0];
	ap[1] = arr2d[1];

	printf("%lld %lld\n", (long long)pa, (long long)(pa + 1)); // 884932082856 884932082872
	printf("%lld %lld\n", (long long)arr2d[0], (long long)arr2d[1]); // 884932082856 884932082872
	printf("%lld %lld\n", (long long)pa[0], (long long)(pa[0] + 1)); // 884932082856 884932082860
	printf("%f\n", pa[0][0]); // 1.000000
	printf("%f\n", *pa[0]); // 1.000000
	printf("%f\n", **pa); // 1.000000
	printf("%f\n", pa[1][3]); // 8.000000
	printf("%f\n", *(*(pa + 1) + 3)); // 8.000000
	printf("\n");

	printf("%lld %lld\n", (long long)ap, (long long)(ap + 1)); // 884932082952 884932082960
	printf("%lld %lld\n", (long long)arr2d[0], (long long)arr2d[1]); // 884932082856 884932082872
	printf("%lld %lld\n", (long long)ap[0], (long long)(ap[0] + 1)); //884932082856 884932082860
	printf("%f\n", ap[0][0]); // 1.000000
	printf("%f\n", *ap[0]); // 1.000000
	printf("%f\n", **ap); // 1.000000
	printf("%f\n", ap[1][3]); // 8.000000
	printf("%f\n", *(*(ap + 1) + 3)); // 8.000000
	printf("\n");

	return 0;
}