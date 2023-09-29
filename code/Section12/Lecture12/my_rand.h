#pragma once

#include <stdio.h>

static unsigned int next = 1;

void MySRand(unsigned int seed)
{
	next = seed;
}

int MyRand()
{
	next = next * 1103515245 + 1234;
	next = (unsigned int)(next / 65536) % 32768;
	return (int)next;
}