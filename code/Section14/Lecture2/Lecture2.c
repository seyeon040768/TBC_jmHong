#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

struct Person // Person is a tag of structure
{
	char name[MAX];
	int age;
	float height;
};

int main(void)
{
	int flag;

	struct Person me;

	strcpy(me.name, "Firstname Lastname");

	me.age = 20;

	flag = scanf("%f", &me.height);
	printf("%f\n", me.height);


	struct Person you = { "First Last", 20, 160.0f };

	struct Person you2 = {
		"First Last",
		20,
		160.0f 
	};

	strcpy(you.name, "First Last");
	you.age = 20;
	you.height = 160.0f;


	struct Person he = {
		.age = 19,
		.name = "Kevin",
		.height = 170.0f
	};


	struct Person* someone;

	someone = &me;

	someone->age = 20;
	printf("%s %d\n", someone->name, (*someone).age);


	struct {
		char farm[MAX];
		float price;
	} apple, apple2;

	strcpy(apple.farm, "AFram");
	apple.price = 1.2f;

	strcpy(apple2.farm, "BFarm");
	apple2.price = 5.6f;


	typedef struct Person MyPerson;

	MyPerson p1;

	typedef struct Person Person;

	Person p2;

	typedef struct {
		char name[MAX];
		char hobby[MAX];
	} friend;

	friend f;

	return 0;
}