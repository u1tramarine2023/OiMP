#include <iostream>
#include<ctime>
/* Написать функцию, которая находит минимальный элемент массива и
возвращает его. С использованием этой функции реализовать сортировку
выбором. Использовать динамический массив.*/
void Allocate(int**, size_t);
//функция нахождение индекса минимального
int find_min(int* arr, int size) {
	int min = arr[0];
	int index_min = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
			index_min = i;
		}
	}
	return index_min;
}

void sort_vyborom(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		int index_min = find_min(arr, size-i);
		std::swap(arr[size - i-1], arr[index_min]);
	}
}
int main()   
{
	int size;
	std::cout << "Input size\n";
	std::cin >> size;
	srand(time(0));
	int* arr = nullptr;
	Allocate(&arr, size);
	//заполнение массива случайными числами 
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	sort_vyborom(arr, size);
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[size - i-1] << " ";
	}
}
void Allocate(int** arr, size_t size) {
	*arr = new int[size];
}
