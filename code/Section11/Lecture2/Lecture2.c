#include <stdio.h>
#include <stdlib.h>

void TestFunction()
{
	int j;
	printf("Stack high \t%llu\n", (unsigned long long)&j);
}


int main(void)
{
	const char* pt2 = "I am a string!.";
	const char* pt3 = "I am a string!.";
	const char* pt4 = "I am a string!!!!!!.";
	const char ar1[] = "I am a string!.";
	const char ar2[] = "I am a string!.";
	const char ar3[] = "I am a string!!.";

	// rodata low      140694964121640 140694964121640 140694964121664 140694964121640
	printf("rodata low \t%llu %llu %llu %llu\n",
		(unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4,
		(unsigned long long)"I am a string!.");
	
	// Stack high      436621931192 436621931240 436621931288
	printf("Stack high \t%llu %llu %llu\n",
		(unsigned long long)ar1, (unsigned long long)ar2, (unsigned long long)ar3);

	// Stack high      436621931096 436621931128 436621931160
	printf("Stack high \t%llu %llu %llu\n",
		(unsigned long long)&pt2, (unsigned long long)&pt3, (unsigned long long)&pt4);


	int i;
	printf("Stack high \t%llu\n", (unsigned long long) & i); // Stack high      436621931332

	TestFunction(); // Stack high      436621930788


	char* p5 = (char*)malloc(sizeof(char) * 100);
	printf("Heap middle \t%llu\n", (unsigned long long)p5); // Heap middle     2404998074768

	char* p6 = (char*)malloc(sizeof(char) * 100);
	printf("Heap middle \t%llu\n", (unsigned long long)p6); // Heap middle     2404998067056


	// ++ar1; // Error
	++pt2;
	puts(pt2); //  am a string!.

	char heart[] = "I love Kelly!";
	const char* head = "I love Helly!";

	for (int i = 0; i < 6; ++i)
	{
		putchar(heart[i]); // I love
	}
	putchar('\n');

	for (int i = 0; i < 6; ++i)
	{
		putchar(*(heart + i)); // I love
	}
	putchar('\n');

	for (int i = 0; i < 6; ++i)
	{
		putchar(*(head + i)); // I love
	}
	putchar('\n');

	while (*(head) != '\0')
	{
		putchar(*(head)); // I love Helly!
		++head;
	}

	head = heart;
	// heart = head; // Error

	heart[7] = 'H';
	*(heart + 7) = 'K';

	putchar('\n');

	char* word = "Goggle";
	// word[2] = 'o'; // Run-time error
	puts(word); // Goggle


	const char* str1 = "when all the lights ar low, ...";
	const char* copy;

	copy = str1;

	// when all the lights ar low, ... 00007FF6195BB108 00000065A8B1F478
	printf("%s %p %p\n", str1, str1, &str1);

	// when all the lights ar low, ... 00007FF6195BB108 00000065A8B1F498
	printf("%s %p %p\n", copy, copy, &copy);

	return 0;
}