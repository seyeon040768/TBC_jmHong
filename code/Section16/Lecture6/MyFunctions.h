#pragma once

extern int status;

static int si = 0;

extern int Add(int a, int b); // �Լ��� �⺻������ extern

static int Multiply(int a, int b)
{
	return a * b;
}

inline int Subtract(int a, int b)
{
	return a - b;
}

void PrintStatus();
void PrintAddress();