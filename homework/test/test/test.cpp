#include <iostream> 

int main() //точка входа в программу на с++ 
{
    //цикл 
    //найти сумму цифр заданного числа 
    int n, sum = 0;
    std::cout << "Enter n\n";
    std::cin >> n;

    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    std::cout << "Summa= " << sum << std::endl;
    return 0;
}
