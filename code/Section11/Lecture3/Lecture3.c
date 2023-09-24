#include <stdio.h>

int main(void)
{
	const char* mythings[5] = {
		"Dancing in the rain",
		"Counting apples",
		"Watching movies with friends",
		"Writing sad letters",
		"Studying the C language",
	};

	char yourthings[5][40] = {
		"Studying the C++ language",
		"Eating",
		"Watching Netflix",
		"Walking around till dark",
		"Deleting spam emails",
	};
	
	const char* temp1 = "Dancing in the rain";
	const char* temp2 = "Studying the C++ language";

	// Dancing in the rain 140695378893960 140695378893960
	printf("%s %llu %llu\n", 
		mythings[0], (unsigned long long)mythings[0], (unsigned long long)temp1);

	// Studying the C++ language 884082734160 140695378894080
	printf("%s %llu %llu\n",
		yourthings[0], (unsigned long long)yourthings[0], (unsigned long long)temp2);
	printf("\n");

	printf("%-30s %-30s\n", "My Things:", "Your Things:");
	for (int i = 0; i < 5; ++i)
	{
		printf("%-30s %-30s\n", mythings[i], yourthings[i]);
	}
	
	printf("\nsizeof mythings: %zd, sizeof yourthings: %zd\n",
		sizeof(mythings), sizeof(yourthings)); // sizeof mythings: 40, sizeof yourthings: 200

	for (int i = 0; i < 100; ++i)
	{
		printf("%c", mythings[0][i]);
	}
	printf("\n");
	printf("\n");

	for (int i = 0; i < 200; ++i)
	{
		printf("%d", (int)yourthings[0][i]);
	}
	printf("\n");

	for (int i = 0; i < 200; ++i)
	{
		printf("%c", yourthings[0][i]);
	}
	printf("\n");

	return 0;
}