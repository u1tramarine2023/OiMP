#include <iostream> 
#include<ctime> 
/* ����������� ������� ��� ��������� ������� ����� �����. �������
������� ����������� ������� ������� � ��������� ��� �������� ����� ���
�� ��������, � ������ ��� � �� �����������. ������� ���������� ������
������������ ��������.*/
void select_sort(int* arr, int size) {
	//���������� ������������
	int min = arr[0];
	int index_min = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
			index_min = i;
		}
	}
	//���������� �� ������ �� ��������
	for (int i = 0; i < index_min; i++)
	{
		for (size_t j = index_min - 1; j > i; j--)
		{
			if (arr[j] > arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
		}
	}
	//���������� � �������� �� �����
	for (int i = index_min + 1; i < size - 1; i++)
	{
		for (size_t j = size - 1; j > index_min; j--)
		{
			if (arr[j] < arr[j - 1])
				std::swap(arr[j], arr[j - 1]);
		}
	}

}
//��������� ������ ��� ������������� ������� 
void Allocate(int**, size_t);
int main()
{
	int size;
	std::cout << "Input size\n";
	std::cin >> size;
	srand(time(0));
	int* arr = nullptr;
	Allocate(&arr, size);
	//���������� ������� ���������� ������� 
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	//��������� �������
	select_sort(arr, size);
	//����� 
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	};
}
void Allocate(int** arr, size_t size) {
	*arr = new int[size];
}

