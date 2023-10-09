#include <iostream>
#include<ctime> 
/* Добавить к некоторой последовательности A=(ai), i=1..n, n<=100,
наименьшее число элементов, чтобы получить арифметическую прогрессию (
напр 22 1 36 -> 1 8 15 22 29 36)*/
void Allocate(int**, size_t);
void Bubblesort(int* arr, size_t size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
}
int NOD(int a, int b) {
	if (a < b) {
		std::swap(a, b);
	}
	while (a % b != 0) {
		a = a % b;
		std::swap(a, b);
	}
	return b;
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
		arr[i] = rand() % 99 +1;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	Bubblesort(arr, size);
	int a;
	int* diff = nullptr;
	Allocate(&diff, size);
	//нахождение разности между числами
	for (int i = 0; i < size; i++)
	{
		 diff[i] = arr[i + 1] - arr[i];
	}
	int first_nod=NOD(diff[0], diff[1]);
	
	int final_nod = first_nod;
	for (int i = 0; i < size-1; i++)
	{
		final_nod =NOD(diff[i], final_nod);

	}
	std::cout << "final NOD=" << final_nod << "\n";
	while (arr[0] <= arr[size-1])

	{
		std::cout << arr[0] << " ";
		arr[0] += final_nod;

	}
}
void Allocate(int** arr, size_t size) {
	*arr = new int[size];
}


