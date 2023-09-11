#include <iostream>
/* 7. Дано четыре числа, если первые два числа больше 5, 
третье число делится на 6, четвертое число не делится на 3,
то вывести yes, иначе no. */
int main()
{
	int a = 6;
	int b = 7;
	int c = 12;
	int d = 10;
	if (a > 5 && b > 5 && c %6==0 && d %3!= 0) std::cout << "yes";
	else std::cout << "no";

	return 0;
}