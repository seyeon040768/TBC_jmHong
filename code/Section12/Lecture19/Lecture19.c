#include <stdio.h>
#include <Windows.h>

//_Atomic int acnt = 0;

DWORD WINAPI ThreadFunc(void* data)
{
	int n = 1;
	Sleep(1000);

	//acnt += n;
	printf("Printing from Thread \n");
	return 0;
}

int main(void)
{
	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	if (thread)
	{
		WaitForSingleObject(thread, INFINITE);
	}

	return 0;
}


/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdatomic.h>

_Atomic int acnt = 0;

void* MyThreadFun(void* vargp)
{
	int n = 1;
	for (int j = 0; j < 10; ++j)
	{
		sleep(1);
		acnt += n;
		printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
	}

	return NULL;
}

int main(void)
{
	pthread_t thread_id1, thread_id2;

	printf("Before Thread\n");

	pthread_create(&thread_id1, NULL, MyThreadFun, NULL);
	pthread_create(&thread_id2, NULL, MyThreadFun, NULL);

	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);

	printf("After Thread\n");
	printf("Atomic %d\n", acnt);

	return 0;
}*/