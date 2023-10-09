#include <iostream>
#include<ctime> 
/*Найти сумму и произведение двух многочленов, заданных массивами
своих коэффициентов.*/
void Allocate(int**, size_t);

int main()
{
	//задаем первый массив
	int size1;
	std::cout << "Input size of first \n";
	std::cin >> size1;
	srand(time(0));
	int* arr1 = nullptr;
	Allocate(&arr1, size1);
	for (size_t i = 0; i < size1; i++)
	{
		arr1[i] = rand() % 10;
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	
	//задаем второй массив
	int size2;
	std::cout << "Input size of second\n";
	std::cin >> size2;
	srand(time(0));
	int* arr2 = nullptr;
	Allocate(&arr2, size2);
	for (size_t i = 0; i < size2; i++)
	{
		arr2[i] = rand() % 10;
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;
	
	int size = size2 > size1 ? size2:size1;
	//разность в количестве коэф-ов
	int shift = std::abs(size1 - size2);
	int* result_sum_arr = nullptr;
	Allocate(&result_sum_arr, size);
	int* result_multi_arr = nullptr;
	int mul_size = size1 + size2 - 1;
	Allocate(&result_multi_arr, mul_size);
	for (int i = 0; i < size; i++)
	{
		result_sum_arr[i] = 0;

		if (size1 == size) {
			result_sum_arr[i] += arr1[i];
			if ((i - shift) >= 0) {
				result_sum_arr[i] += arr2[i - shift];
			}
		}
		else {
			if ((i - shift) >= 0) {
				result_sum_arr[i] += arr1[i - shift];
			}
			result_sum_arr[i] += arr2[i];
		}
		std::cout << result_sum_arr[i] << " ";

	}
	std::cout << std::endl;
	for (size_t i = 0; i < mul_size; i++)
	{
		result_multi_arr[i] = 0;
	}
	for (size_t i = 0; i < size1; i++)
	{
		int power1 = size1 - i;
		for (size_t k = 0; k < size2; k++)
		{
			int power2 = size2 - k;
			result_multi_arr[mul_size - power1 - power2+1] += arr1[i] * arr2[k];
		}
	}
	for (size_t i = 0; i < mul_size; i++)
	{
		std::cout << result_multi_arr[i] << " ";
	}
}
void Allocate(int** arr, size_t size) {
	*arr = new int[size];
}
