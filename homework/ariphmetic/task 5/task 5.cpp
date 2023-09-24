#include <iostream>
/* Для заданного N найти все меньшие его числа Армстронга (n-значное
число называется числом Армстронга, если оно равно сумме n-х степеней
своих цифр, например, 153=1^3+5^3+3^3) */
int power(int a, int b) { //возведение в степень
	int result = 1;
	for (int i = 1; i <= b; i++)
	{
		result = result * a;
	}
	return result;
}
int num_of_digits(int n) {
	int i = 1;
	while (n >= 10) {
		n = n / 10;
		i++;
	}
	return(i);
}
void armstrong(int n) {
	int i = 1;
	int ost;
	int sum = 0;
	int num_dig = num_of_digits(n);
	int k = n;
	while (k >= 1) {
		ost = k % 10;
		sum += power(ost, num_dig);
		i++;
		k = (k - ost) / 10;
	}
	if (n == sum) std::cout << n << " ";
}
int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		armstrong(i);
	}

}
