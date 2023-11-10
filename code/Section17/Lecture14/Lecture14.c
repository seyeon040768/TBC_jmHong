#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedQueue.h"

#define PROMPT ">>"

int InputInt()
{
	int num;

	scanf("%d", &num);

	while (getchar() != '\n');

	return num;
}

void MakeRandomNumbers(int count, int* array)
{
	for (int i = 0; i < count; ++i)
	{
		*(array + i) = rand() % 60;
	}
}

Item GetItem(int arrivalTime, int processTime)
{
	Item item = { .arrivalTime = arrivalTime, .processTime = processTime };

	return item;
}

bool AddOrder(Queue* orderQueue, int arrivalTime, int processTime)
{
	if (IsFull(orderQueue))
	{
		return false;
	}

	EnQueue(GetItem(arrivalTime, processTime), orderQueue);

	printf(" %d: a new customer enqueue.\n", arrivalTime);

	return true;
}

int main(void)
{
	Queue orderQueue;
	Initialize(&orderQueue);

	int simulationHours, customerPerHour;
	int accepted = 0;
	int served = 0;
	int lost = 0;
	int remainedTime = 0;

	double avgQueueSize = 0.0;
	double avgWaitTime = 0.0;

	srand(time(NULL));

	printf("How many hours do you want to simulate?\n");
	printf("%s ", PROMPT);
	simulationHours = InputInt();

	printf("How many customers per hour do you expect?\n");
	printf("%s ", PROMPT);
	customerPerHour = InputInt();


	int* randomMinutes = (int*)malloc(customerPerHour * sizeof(int));
	if (randomMinutes == NULL)
	{
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < simulationHours; ++i)
	{
		MakeRandomNumbers(customerPerHour, randomMinutes);

		for (int j = 0; j < 60; ++j)
		{
			for (int k = 0; i < customerPerHour; ++k)
			{
				if (*(randomMinutes + k) == j)
				{
					if (AddOrder(&orderQueue, j, rand() % 3 + 1))
					{
						++accepted;
					}
					else
					{
						++lost;
					}
				}
			}

		}
	}
	free(randomMinutes);



	return 0;
}