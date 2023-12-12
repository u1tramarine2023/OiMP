#include <iostream> 
#include <string> 
#include <fstream>  
#include <bitset> 
#include <vector> 
typedef bool (*ptr_function)(int);

bool IsOdd(int a) { return a % 2 != 0; }
bool IsEven(int a) { return a % 2 == 0; }
bool IsPrime(int a) {
    for (size_t i = 2; i <= a / 2; i++)
    {
        if (a % i == 0) return false;
    }
    return true;
}
void PrintElemets(std::vector<int> v, ptr_function)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (ptr_function(v[i])) std::cout << v[i] << " ";
    }
    std::cout << "\n";
}
int main() {
    std::vector<int> v = { 2,7,12,23,17,18 };
    ptr_function a = IsOdd;
    ptr_function arr_func[] = { IsOdd ,IsEven, IsPrime };
    std::vector<ptr_function> v_function;
    PrintElemets(v, IsOdd);
    PrintElemets(v, IsEven);
    PrintElemets(v, IsPrime);
    return 0;
}