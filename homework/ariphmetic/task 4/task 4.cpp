#include <iostream>
/* Определить, между какими двумя последующими степенями двойки
расположено заданное число*/
int power(int a, int b) { //возведение в степень
    int result = 1;
    for (int i = 1; i <= b; i++)
    {
        result = result * a;
    }
    return result;
}
void btw_stepen_founder(int n) {
    int i = 0;
    while (n > power(2, i))
        i++;
    std::cout << "Number is between 2^" << i - 1 << " and 2^" << i;
}

int main()
{
    int n;
    std::cin >> n;
    btw_stepen_founder(n);
}
