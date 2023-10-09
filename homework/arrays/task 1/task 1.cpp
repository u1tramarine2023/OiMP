#include <iostream>
/* Дан массив целых чисел, в котором все числа кроме одного встречаются
четное количество раз, одно число встречается нечетное количество раз.
Найти это число.*/
int main()
{
	const int size = 7;
	int numbers[size]{ 2,2,3,4, 4, 3, 7};
	for (int i = 0; i < size; i++)
	{
		int num_i = numbers[i];
		int sum_num = 1;
		for (int j = 0; j < size; j++)
		{
			if (num_i == numbers[j] && i!=j) sum_num++;
		}
		if (sum_num % 2 !=0) {
			std::cout << numbers[i]; break;
		}
	}
}
