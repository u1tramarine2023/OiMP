

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
	/////////////////////чтение из файла 
	std::ifstream fin("program.cpp");
	std::ofstream fout("output.txt");

	if (!fin.is_open())//проверка на корректность открытия файла!!! 
	{
		std::cout << "Error file open\n";
		return 1;
	}
	////////////////////////// //возведение в квадрат
	int sqr(int  i) { 
		i = i * i;
		return i;
	}
	/////////////////возведение в степень
	int power(int a, int b) { 
		int result = 1;
		for (int i = 1; i <= b; i++)
		{
			result = result * a;
		}
		return result;
	}
	/////////////////////// нахождение числа цифр в числе
	int num_of_digits(int n) {
		int i = 1;
		while (n >= 10) {
			n = n / 10;
			i++;
		}
		return(i);
	}
	/////////////// проверка на високосный год
	(i % 4 == 0 and i % 100 != 0 or i % 400 == 0) ? 1 : 0;
	////////////////////сортировка выбором
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
		//////////////////нод
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
		///////////////////////////
#include <iostream> 
#include <algorithm> 
#include<ctime> 
#include<vector> 
//заполнение массива случайными числами 

		void InitArray(std::vector<int>&);
		void PrintArray(const std::vector<int>&);
		int BinarySearch(const std::vector<int>&, int, int, int);
		void InsetSort(std::vector<int>&);

		int gcd(int a, int b) {
			if (b == 0)
				return a;
			else return gcd(b, a % b);
		}

		std::vector< int >build_progression(std::vector<int>& arr) {
			std::sort(arr.begin(), arr.end());
			std::vector < int > ans;
			int diff = arr[1] - arr[0];
			for (int i = 1; i < size(arr) - 1; i++) {
				diff = gcd(diff, arr[i + 1] - arr[i]);
			}
			for (int i = arr[0]; i <= arr[size(arr) - 1]; i += diff)
				ans.push_back(i);
			return ans;
		}

		int main()
		{
			std::vector<int> A = { 1 , 22 , 36 };
			//InitArray(A); 
			PrintArray(A);
			std::vector<int> progression = build_progression(A);
			PrintArray(progression);

		}

		void InsetSort(std::vector<int>& arr)
		{
			for (size_t i = 1; i < size(arr); i++)
			{
				int temp = arr[i];
				int pos = BinarySearch(arr, temp, 0, i);
				int j;
				for (j = i - 1; j >= pos; j--)
				{
					arr[j + 1] = arr[j];
				}
				arr[j + 1] = temp;
			}
		}



		void InitArray(std::vector<int>& arr)
		{
			for (size_t i = 0; i < arr.size(); i++)
			{
				arr[i] = rand() % (122 - 65) + 65;
			}
		}

		void PrintArray(const std::vector<int>& arr) {
			for (size_t i = 0; i < size(arr); i++)
			{
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl;
		}


		int BinarySearch(const std::vector<int>& arr, int key, int first, int last) {

			int mid;
			/* Calculate mid element */
			mid = (first + last) / 2;
			/* If mid is equal to number we are searching */
			if (arr[mid] == key) {
				return mid;
			}
			else if (last == first) return last;
			else if (arr[mid] > key) {
				BinarySearch(arr, key, first, mid);
			}
			else {
				BinarySearch(arr, key, mid + 1, last);
			}

		}
		/////////////
#include <iostream> 
#include<ctime> 
//выделение памяти для динамического массива 
		template< typename T >
		void Allocate(T*&, size_t);
		//заполнение массива случайными числами 
		void InitArray(int*, size_t);
		void InitArray(double*, size_t);
		void InitArray(char*, size_t);
		//выводит массив 
		template< typename T >
		void PrintArray(T*, size_t);

		//освобождение памяти 
		template< typename T >
		void Diallocate(T*&);

		template<typename T>
		int BinarySearch(T*, T, int, int);
		template<typename T>
		void InsetSort(T*, size_t);


		int main()
		{
			int A[6] = { 1,-6 ,12,-17,34,-35 };
			PrintArray(A, 6);
			InsetSort(A, 6);
			PrintArray(A, 6);

		}
		template<typename T>
		void InsetSort(T* arr, size_t size)
		{
			for (size_t i = 1; i < size; i++)
			{
				T temp = arr[i];
				int pos = BinarySearch(arr, temp, 0, i);
				int j;
				for (j = i - 1; j >= pos; j--)
				{
					arr[j + 1] = arr[j];
				}
				arr[j + 1] = temp;
			}
		}

		template< typename T >
		void Allocate(T*& arr, size_t size) {
			arr = new T[size];
		}
		void InitArray(int* arr, size_t size)
		{

			for (size_t i = 0; i < size; i++)
			{
				arr[i] = rand() % 100;
			}
		}
		//Перегрузка 
		void InitArray(double* arr, size_t size)
		{

			for (size_t i = 0; i < size; i++)
			{
				arr[i] = rand() % 100 * 0.04;
			}
		}
		void InitArray(char* arr, size_t size)
		{

			for (size_t i = 0; i < size; i++)
			{
				arr[i] = rand() % (122 - 65) + 65;
			}
		}
		template< typename T >
		void PrintArray(T* arr, size_t size) {
			for (size_t i = 0; i < size; i++)
			{
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl;
		}
		template< typename T >
		void Diallocate(T*& arr)
		{
			delete[]arr;
			arr = nullptr;
		}

		template<typename T>
		int BinarySearch(T* arr, T key, int first, int last) {

			int mid;
			/* Calculate mid element */
			mid = (first + last) / 2;
			/* If mid is equal to number we are searching */
			if (arr[mid] == key) {
				return mid;
			}
			else if (last == first) return last;
			else if (arr[mid] > key) {
				BinarySearch(arr, key, first, mid - 1);
			}
			else {
				BinarySearch(arr, key, mid + 1, last);
			}

		}
}

