#include <iostream> 
#include<iomanip> 
double Sqrt(double);//прототип функции (объявление функции) 

int main()
{
    double a, result;
    std::cout << "Input a\n";
    std::cin >> a;
    result = Sqrt(a);
    std::cout << std::fixed << std::setprecision(12) << " sqtr(" << a << ")= " << result << std::endl;
}
double Sqrt(double a) //реализация функции (определение функции) 
{
    const double eps = 0.00000000001;
    double xn, xn1;
    xn = xn1 = a;
    do {
        xn = xn1;
        xn1 = (xn + a / xn) / 2;
    } while (abs(xn - xn1) > eps);
    return xn1;
}