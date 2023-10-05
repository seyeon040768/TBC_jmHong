/*#include <stdio.h>

#define LEN 20

struct Names
{
	char given[LEN];
	char family[LEN];
};

struct Friend
{
	struct Names fullName;
	char mobile[LEN];
};

int main(void)
{
	struct Friend myFriends[2] = {
		{{"Ariana", "Grande"}, "1234-1234"},
		{{"Taylor", "Swift"}, "6550-8888"}
	};

	struct Friend* girlFriend;

	girlFriend = &myFriends[0];

	printf("%zd\n", sizeof(struct Friend)); // 60
	printf("%llu %s\n", (unsigned long long)girlFriend, girlFriend->fullName.given); // 379321841728 Ariana

	++girlFriend;

	printf("%llu %s\n", (unsigned long long)girlFriend, girlFriend->fullName.given); // 379321841788 Taylor

	return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>

struct MyData
{
	int a;
	char c;
	float arr[2];
};

int main(void)
{
	struct MyData d1 = { 1234, 'A' };

	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %llu\n", d1.a, d1.c, (unsigned long long)d1.arr); // 1234 A 453786990480
	printf("%f %f\n", d1.arr[0], d1.arr[1]); // 1.100000 2.200000
	printf("%llu %llu\n\n", (unsigned long long) & d1.arr[0], (unsigned long long) & d1.arr[1]); // 453786990480 453786990484

	struct MyData d2 = d1;

	printf("%d %c %llu\n", d2.a, d2.c, (unsigned long long)d2.arr); // 1234 A 453786990528
	printf("%f %f\n", d2.arr[0], d2.arr[1]); // 1.100000 2.200000
	printf("%llu %llu\n\n", (unsigned long long) & d2.arr[0], (unsigned long long) & d2.arr[1]); // 453786990528 453786990532

	return 0;
}*/


#include <stdio.h>
#include <stdlib.h>

struct MyData
{
	int a;
	char c;
	float* arr;
};

int main(void)
{
	struct MyData d1 = { 1234, 'A', NULL };
	d1.arr = (float*)malloc(sizeof(float) * 2);
	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %llu\n", d1.a, d1.c, (unsigned long long)d1.arr); // 1234 A 2213571199536
	printf("%f %f\n", d1.arr[0], d1.arr[1]); // 1.100000 2.200000
	printf("%llu %llu\n\n", (unsigned long long) & d1.arr[0], (unsigned long long) & d1.arr[1]); // 2213571199536 2213571199540

	struct MyData d2 = d1;

	printf("%d %c %llu\n", d2.a, d2.c, (unsigned long long)d2.arr); // 1234 A 2213571199536
	printf("%f %f\n", d2.arr[0], d2.arr[1]); // 1.100000 2.200000
	printf("%llu %llu\n\n", (unsigned long long) & d2.arr[0], (unsigned long long) & d2.arr[1]); // 2213571199536 2213571199540

	free(d1.arr);

	return 0;
}