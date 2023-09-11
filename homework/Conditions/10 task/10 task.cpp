#include <iostream>

int main()
/* 10. Написать программу-калькулятор для логических операций. 
Пользователь вводит два значения типа bool и выбирает  действие.
Вывести на экран результат. */
{
	std::cout << "Insert two bool values\n";
	bool a;
	bool b;
	std::cin >> a >> b;
	std::cout << "Select operation: 1 - and, 2 - or, 3 - xor\n";
	int x;
	std::cin >> x;
	switch (x)  {
	case 1:
		std::cout << (a && b);
		break;
	case 2:
		std::cout << (a || b);
		break;
	case 3:
		std::cout << (a ^ b);
		break;
	}
	return 0;
}

