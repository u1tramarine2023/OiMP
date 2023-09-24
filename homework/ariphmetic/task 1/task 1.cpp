#include <iostream>
/*Для заданного N найти все меньшие его автоморфные числа
(автоморфным называется число, совпадающее с младшими цифрами своего
квадрата)
*/
int sqr(int  i) { //возведение в квадрат
    i=i* i;
    return i;
    }
int power(int a,int b) { //возведение в степень
    int result=1;
    for (int i = 1; i <=b; i++)
    {
        result = result * a;
    }
    return result;
}
bool automorph(int n, int square_n) {
    int i=1; //степень
  while (true)
    {
      int d = power (10, i);
      if (d > square_n) break;
      int ost = square_n % d;
      if (ost == n) return true;
      i++;

    }
    return false;
}
int main()
{
    int n;
    std::cout << "Input n \n";
    std::cin >> n;
    int c=1;
    while (c < n) {
       bool result= automorph(c, sqr(c));
        if (result) std::cout << c <<" "<< sqr(c) <<"\n";
        c++;
    }
}

