

#include <iostream>

/*1. Даны два числа. Если первое число больше второго,
то вывести yes, иначе поменять значения этих переменных местами и вывести их на экран.*/
int main()
{
	int a = 4;
	int b = 7;
	if (a > b)
	{
		std::cout << "yes\n";
	}
	else
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
		std::cout << "a=" << a << " b=" << b;
	}
	return 0;
}
