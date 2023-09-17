#include <iostream>
//Найти все несократимые, простые дроби, знаменатель которых меньше заданного числа.  
int main()
{
	int n, chis, znam;

	while (true) {

		std::cin >> n;
		chis = 1;
		while (chis < n - 1) {
			znam = chis + 1;
			while (znam < n) {
				if (znam % chis != 0 || chis == 1) //
					std::cout << chis << "/" << znam << "\n";
				znam++;
			}
			chis++;
		}

	}
	return 0;
}

