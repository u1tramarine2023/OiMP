#include <iostream>
/* Из последовательности целых чисел выбрать три числа, произведение
которых максимально.*/
bool check(int* numbers, int position) {
	for (int i = 0; i < 3; i++)
	{
		if (numbers[i] == position) return true;
	}
	return false;
}
int main()
{
	const int size = 7;
	int numbers[size]{ 5,8,4, 9, 3, 9, 9 };
	int max_num[3]{ -1,-1,-1 };
	int max;
	int proizvedenie = 1;
	for (int k = 0; k < 3; k++)
	{
			for (int i = 0; i < size; i++) {
			if (check(max_num, i)) {
				continue;
			}
				bool big = true;
				for (int j = i + 1; j < size; j++)
				{
					if (check(max_num, j)) {
						continue;
					}
					if (numbers[j] > numbers[i])
					{
						big = false;
						break;
					}

				}
			
				if (big) {
					max_num[k] = i; 
					break;
				}
		}

	}
	for (int i = 0; i < 3; i++)
	{
		proizvedenie *= numbers[max_num[i]];
	}
	std::cout << proizvedenie;
}

