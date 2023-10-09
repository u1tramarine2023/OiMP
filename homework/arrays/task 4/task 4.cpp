#include <iostream> 
#include<ctime> 
/* –еализовать функцию дл€ обработки массива целых чисел. ‘ункци€
находит минимальный элемент массива и сортирует все элементы левее его
по убыванию, а правее его Ц по возрастанию. ‘ункци€ возвращает индекс
минимального элемента.*/
void select_sort(int* arr, int size) {
	//нахождение минимального
	int min = arr[0];
	int index_min = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
			index_min = i;
		}
	}
	//сортировка от начала до элемента
	for (int i = 0; i < index_min; i++)
	{
		for (size_t j = index_min - 1; j > i; j--)
		{
			if (arr[j] > arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
		}
	}
	//сортировка с элемента до конца
	for (int i = index_min + 1; i < size - 1; i++)
	{
		for (size_t j = size - 1; j > index_min; j--)
		{
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
		}
	}

}
//выделение пам€ти дл€ динамического массива 
void Allocate(int**, size_t);
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
	//выполение функции
	select_sort(arr, size);
	//вывод 
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	};
}
void Allocate(int** arr, size_t size) {
	*arr = new int[size];
}

