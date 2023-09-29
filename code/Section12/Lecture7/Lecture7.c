#include <stdio.h>

int* Count(void)
{
	int ct = 0;
	printf("count = %d %llu\n", ct, (unsigned long long) & ct);
	++ct;

	return &ct; // warning
}

int* StaticCount(void)
{
	static int ct = 0;
	printf("static count = %d %llu\n", ct, (unsigned long long) & ct);
	++ct;

	return &ct;
}

void CounterCaller(void)
{
	Count();
}

void StaticCounterCaller(void)
{
	StaticCount();
}

int main(void)
{
	Count(); // count = 0 200921577700
	Count(); // count = 0 200921577700
	CounterCaller(); // count = 0 200921577444

	StaticCount(); // static count = 0 140700539146608
	StaticCount(); // static count = 1 140700539146608
	StaticCounterCaller(); // static count = 2 140700539146608

	return 0;
}