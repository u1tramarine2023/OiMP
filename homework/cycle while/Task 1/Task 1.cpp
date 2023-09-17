#include <iostream>
/*Дано натуральное число n. Определите,
является ли оно степенью числа 2, и выведите слово YES, 
если является и слово NO, если не является.  */
int main()
{
	int n;
	
		while (true) {

			std::cin >> n;
			while (n % 2 == 0 && n != 0) 
				n = n / 2; //делим число на 2 макс. количество раз
			if (n == 1)
				std::cout << "yes\n";
			else
				std::cout << "no\n";
		}
	return 0;
}

