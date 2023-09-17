#include <iostream>
// Написать программу, которая вычисляет дату предыдущего дня. 
int main()
{
	enum {
		jan = 1,
		feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	int monthDuration{};
	int day, month, year;
	std::cout << "Input date (format: day month year): ";
	std::cin >> day >> month >> year;

	if (day == 1) {

		if (month == 1) {
			year--;
			month = 12;
			day = 31;
		}
		else {
			month--;
			switch (month)
			{
			case jan: case mar: case may: case jul: case aug: case oct: case dec:
				monthDuration = 31; break;
			case apr: case jun: case sep: case nov:
				monthDuration = 30; break;
			case feb:
				monthDuration = (year % 4 == 0 and year % 100 != 0 or year % 400 == 0) ? 29 : 28;
				break;
			default:
				std::cout << "Wrong month\n";
				break;
			}
			day = monthDuration;
		}
	}
	else {
		day--;
	}
	std::cout << day << " " << month << " " << year;

	return 0;

}