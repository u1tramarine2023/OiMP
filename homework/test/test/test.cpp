#include <iostream> 
#include<ctime> 
void Allocate(int**, size_t);
int main()
{
	int* arr = nullptr;
	int size = 4;
	srand(time(0));
	Allocate(&arr, size);
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		std::cin >> arr[i];
		sum += arr[i];
	}
	std::cout << sum;
}
void Allocate(int** arr, size_t size) {
	*arr = new int[size];
}