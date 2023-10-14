#include <stdio.h>

#define BYTE_MASK 0xff

int main(void)
{
	unsigned int rgbaColor = 0x66CDAAFF;
	// 4 bytes, medium aqua marine (102, 205, 170, 255)

	unsigned char red, green, blue, alpha;

	alpha = (rgbaColor >> 0) & BYTE_MASK;
	blue = (rgbaColor >> 8) & BYTE_MASK;
	green = (rgbaColor >> 16) & BYTE_MASK;
	red = (rgbaColor >> 24) & BYTE_MASK;

	printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n",
		red, green, blue, alpha); // (R, G, B, A) = (102, 205, 170, 255)

	return 0;
}