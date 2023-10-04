#include <stdio.h>

#define LEN 20

struct Names
{
	char given[LEN];
	char family[LEN];
};

struct Reservation
{
	struct Names guest;
	struct Names host;
	char food[LEN];
	char place[LEN];

	int year;
	int month;
	int day;
	int hours;
	int minutes;
};

int main(void)
{
	struct Reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"the Gatsby mansion"},
		.food = {"Escargot"},
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};

	printf("Dear %s %s,\n", res.guest.given, res.guest.family);
	printf("I would like to serve you %s\n", res.food);
	printf("Please visit %s one %d/%d/%d at %d:%d.\n",
		res.place, res.day, res.month, res.year, res.hours, res.minutes);
	printf("Sincerely,\n");
	printf("%s %s\n", res.host.given, res.host.family);

	return 0;
}