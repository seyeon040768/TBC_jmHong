#pragma once

#include <stdio.h>

static void DifferentFuncInDifferentFile()
{
	printf("__FILE__: %s\n", __FILE__);
	printf("__func__: %s\n", __func__); // __func__: DifferentFuncInDifferentFile
}