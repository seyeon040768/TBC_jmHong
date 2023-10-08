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

union Data
{
	struct PersonalOwner po;
	struct CompanyOwner co;
};

struct CarData
{
	char model[15];
	int status; // 0: personal, 1: company
	union Data ownerInfo;
};

void PrintCar(struct CarData car)
{
	printf("------------------------------\n");
	printf("Car model: %s\n", car.model);

	if (car.status == 0)
	{
		printf("Personal owner: %s-%s\n",
			car.ownerInfo.po.rrn1, car.ownerInfo.po.rrn2);
	}
	else
	{
		printf("Company owner: %s-%s-%s\n",
			car.ownerInfo.co.crn1, car.ownerInfo.co.crn2, car.ownerInfo.co.crn3);
	}
	printf("------------------------------\n");
}

int main(void)
{
	struct CarData myCar = { .model = "AAAAA", .status = 0, .ownerInfo.po = {"123456", "1234567"} };
	struct CarData companyCar = { .model = "BBBBB", .status = 1, .ownerInfo.co = {"123", "12", "12345"} };

	PrintCar(myCar);
	PrintCar(companyCar);

	return 0;

	return 0;
}