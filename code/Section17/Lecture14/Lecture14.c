#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedQueue.h"

#define PROMPT ">>"

int InputInt()
{
	int num;

	while (scanf("%d", &num) != 1)
	{
		while (getchar() != '\n');
	}

	while (getchar() != '\n');

	return num;
}

void MakeRandomNumbers(int range, int count, int* array)
{
	for (int i = 0; i < count; ++i)
	{
		*(array + i) = rand() % range;
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

	int simulationHours, customerPerHour, totalHours, totalCustomers;
	int accepted = 0;
	int served = 0;
	int lost = 0;
	int remainedTime = 0;

	double avgQueueSize = 0.0;
	double avgWaitTime = 0.0;

	Item temp;

	srand(time(NULL));

	printf("How many hours do you want to simulate?\n");
	printf("%s ", PROMPT);
	simulationHours = InputInt();

	printf("How many customers per hour do you expect?\n");
	printf("%s ", PROMPT);
	customerPerHour = InputInt();

	totalHours = simulationHours * 60;
	totalCustomers = simulationHours * customerPerHour;


	int* randomMinutes = (int*)malloc(totalCustomers * sizeof(int));
	if (randomMinutes == NULL)
	{
		exit(EXIT_FAILURE);
	}
	MakeRandomNumbers(totalHours, totalCustomers, randomMinutes);

	for (int m = 0; m < totalHours; ++m)
	{
		for (int k = 0; k < totalCustomers; ++k)
		{
			if (*(randomMinutes + k) == m)
			{
				if (AddOrder(&orderQueue, m, rand() % 3 + 1))
				{
					++accepted;
				}
				else
				{
					printf(" %d: Customer lost\n", m);
					++lost;
				}
			}
		}

		if (remainedTime <= 0 && !IsEmpty(&orderQueue))
		{
			DeQueue(&temp, &orderQueue);

			printf(" %d: start serving a customer for %d minutes.\n", m, temp.processTime);

			remainedTime = temp.processTime;

			++served;

			avgWaitTime += m - temp.arrivalTime;
		}
		--remainedTime;

		avgQueueSize += orderQueue.itemCount;
	}
	free(randomMinutes);

	avgQueueSize /= simulationHours;

	while (DeQueue(&temp, &orderQueue))
	{
		avgWaitTime += temp.arrivalTime;
	}
	avgWaitTime /= accepted;

	printf("customers accepted: %d\n", accepted);
	printf("customers served: %d\n", served);
	printf("Lost: %d\n", lost);
	printf("average queue size: %.2lf\n", avgQueueSize);
	printf("average wait time: %.2lf minutes\n", avgWaitTime);

	return 0;
}