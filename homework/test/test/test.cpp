#include <iostream> 

int main() //����� ����� � ��������� �� �++ 
{
    //���� 
    //����� ����� ���� ��������� ����� 
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
