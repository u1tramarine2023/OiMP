#include <iostream>
/* 
4. ������������ ������ ������ �����. ������� ���������� ������ ����� ����� ���. ���� ��� �� ����������, �������� ����� "not found" */
int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int n1, n2, n3, n4;
    // ���������� ������ �����
    if (a % 2 == 0) n1 = a;
    else n1 = 0;
    if (b % 2 == 0) n2 = b;
    else n2 = 0;
    if (c % 2 == 0) n3 = c;
    else n3 = 0;
    if (d % 2 == 0) n4 = d;
    else n4 = 0;
    // ���������� �������� �������
    int x;
    if (n1 > n2) x = n1;
    else x = n2;
    if (n3 > x) x = n3;
    if (n4 > x) x = n4;
    // ����� ����������
    if (x != 0) std::cout << x;
    else std::cout << "Not found";
    return 0;
}


