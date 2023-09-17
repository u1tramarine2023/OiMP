#include <iostream>
// По данному натуральному числу n найдите сумму чисел 1+1/1!+1/2!+1/3!+...+1/n!.
int main()
{
	int a, i, n;
	double result = 1;
	i = 1; //счетчик действий
	std::cin >> n;
	while (i <= n) {
		double factorial = 1.;
		int k = 1; //счетчик для факториала
		while (k <= i) { //факториал для каждого члена суммы
			factorial /= k; // т.к. 1/(1*2*к)=1/2/к
			k++;
		}
		result += factorial;
		i++;
	}
	std::cout << result << "\n";
	return 0; //Стремиться к 2.71828
}


