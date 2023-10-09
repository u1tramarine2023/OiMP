#include <iostream>
#include<ctime> 
/* Написать программу, которая содержит функцию, принимающую в
качестве аргумента, два массива (А и В) и размеры массивов. Функция
проверяет, является ли массив В подмножеством (подстрокой) массива А и
возвращает указатель на начало найденного фрагмента, если элемента нет,
возвращает 0*/
void Allocate(int**, size_t);
int* check_podmnoj(int* arrA, int* arrB, int sizeA, int sizeB)
{
    int* ptr;
    for (int i = 0; i < sizeA; i++)
    {
        int j = i, k = 0;
        while (j < sizeA && k < sizeB && arrB[k] == arrA[j])
        {
            j++;
            k++;
        }
        if (k == sizeB) {
           return  ptr=&arrA[i];
        }
    }
    return 0; 
}
int main(){

    int sizeA = 7;
    int arrA[7]{ 0, 0, 0, 1, 2, 3 ,4 };
    int sizeB = 3;
    int arrB[3]{ 2,3,4 };
    int* printptr = check_podmnoj(arrA, arrB, sizeA, sizeB);
    std::cout << "Podmnojestvo s " << printptr;
}

void Allocate(int** arr, size_t size) {
    *arr = new int[size];
}
