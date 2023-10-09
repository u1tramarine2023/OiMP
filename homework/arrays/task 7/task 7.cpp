#include <iostream>
#include <ctime>
/* Написать функцию, которая производит двоичный поиск места
размещения нового элемента в упорядоченном массиве и возвращает место
включения нового элемента. С помощью данной функции реализовать
сортировку вставками*/
// отображение массива
void PrintArray(int* array, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

//создаёт динамический массив
int* InitArray(int* array, int size)
{
    array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 50 + 1;
    }
    return array;
}

//бинарный поиск
int BinarySearch(int* array, int start, int finish, int num)
{
    if (num >= array[finish])
        return finish + 1;

    int pos = (finish + start) / 2;

    if (start == finish)
        return pos;

    else {
        if (array[pos] > num) {
            BinarySearch(array, start, pos - 1, num);
        }
        else {
            BinarySearch(array, pos + 1, finish, num);
        }
    }
}

//сортировка массива с помощью бинарного поиска
void sortArray(int* array, int size)
{
    int newPos;
    for (int i = 1; i < size; i++) {
        newPos = BinarySearch(array, 0, i - 1, array[i]);
        for (int j = i; j > newPos; j--) {
            std::swap(array[j], array[j - 1]);
        }
    }
}

int main()
{
    srand(time(0));

    int* array = nullptr;
    int size = 10;
    array = InitArray(array, size);
    PrintArray(array, size);
    sortArray(array, size);
    PrintArray(array, size);

    delete[] array;
    return 0;
}