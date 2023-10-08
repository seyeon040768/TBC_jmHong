#include <stdio.h>

struct PersonalOwner
{
	char rrn1[7]; // Resident Registration Number
	char rrn2[8]; // 123456-1234567
};

struct CompanyOwner
{
	char crn1[4]; // Company Registration Number
	char crn2[3]; // 123-12-12345
	char crn3[6];
};



struct CarData
{
	char model[15];
	int status; // 0: personal, 1: company
	union
	{
		struct PersonalOwner po;
		struct CompanyOwner co;
	};
};

void PrintCar(struct CarData car)
{
	printf("------------------------------\n");
	printf("Car model: %s\n", car.model);

	if (car.status == 0)
	{
		printf("Personal owner: %s-%s\n",
			car.po.rrn1, car.po.rrn2);
	}
	else
	{
		printf("Company owner: %s-%s-%s\n",
			car.co.crn1, car.co.crn2, car.co.crn3);
	}
	printf("------------------------------\n");
}

int main(void)
{
	struct CarData myCar = { .model = "AAAAA", .status = 0, .po = {"123456", "1234567"} };
	struct CarData companyCar = { .model = "BBBBB", .status = 1, .co = {"123", "12", "12345"} };

	PrintCar(myCar);
	PrintCar(companyCar);


	struct Vector2D
	{
		union
		{
			struct { double x, y; };
			struct { double i, j; };
			struct { double arr[2]; };
		};
	};

	typedef struct Vector2D vec2;

	vec2 v = { 3.14, 2.99 };
	printf("%.2f %.2f\n", v.x, v.y);
	printf("%.2f %.2f\n", v.i, v.j);
	printf("%.2f %.2f\n", v.arr[0], v.arr[1]);

	for (int d = 0; d < 2; ++d)
	{
		printf("%.2f ", v.arr[d]);
	}

	return 0;
}