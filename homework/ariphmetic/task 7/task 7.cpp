#include <iostream>
/*Пользователь вводит дату своего рождения и текущую дату. Посчитать
количество прожитых дней.*/
int month_days(int month_num, int year) {
	enum {
		jan = 1,
		feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	int add_days = 0;
	switch (month_num)
	{
	case jan:  add_days = 1; break;
	case mar: add_days = 2; break;
	case apr: add_days = 2; break;
	case may:case jun: add_days = 3; break;

	case jul:add_days = 4; break;
	case aug: case sep: add_days = 5; break;
	case oct: case nov: add_days = 6; break;

	case feb:
		add_days = (year % 4 == 0 and year % 100 != 0 or year % 400 == 0) ? 0 : -1;
		break;
	}
	return add_days;
}
int num_of_leap_years(int year) {
	int result = 0;
	for (int i=0; i <year; i++)
	{
		result+= (i % 4 == 0 and i % 100 != 0 or i % 400 == 0) ? 1 : 0;
	}
	return result;
}
int days(int day, int month, int year) {
	int day_dur = day-1;
	int month_dur = (month - 1) * 30 + month_days(month - 1, year);
	int year_dur = (year-1) * 365 + num_of_leap_years(year);
	return day_dur + month_dur + year_dur;
}

int main()
{

	int day1, month1, year1;
	std::cout << "Input your birthday (format: day month year): ";
	std::cin >> day1 >> month1 >> year1;
	int day2, month2, year2;
	std::cout << "Input current date (format: day month year): ";
	std::cin >> day2 >> month2 >> year2;
	std::cout << days(day2, month2, year2) - days(day1, month1, year1);

}
