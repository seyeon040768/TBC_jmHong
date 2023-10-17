#include <stdio.h>
#include "MyFunctions.h"
#include "MyStructures.h"
#include "MyHeaders/MyMacros.h"
/*
Properties
-> Configuration Properties
-> C/C++
-> General
-> Additional Include Directories�� ���� ���� �Է�(MyHeaders)

#include "MyMacros.h" or #include <MyMacros.h> ��� ����
*/

extern int status;

int main(void)
{

#include "HelloWorld.h"

	printf("Pi = %f", PI);

	printf("%p %d\n", &status, status);

	PrintStatus();

	printf("%d\n", Multiply(51, 2));

	printf("main()\n");
	printf("Static function address %p\n", Multiply);
	printf("Static variable address %p\n", &si);

	PrintAddress();

	patientInfo james = { "James Bone", 45 }, michael = { "Michael Jobs", 50 };

	return 0;
}