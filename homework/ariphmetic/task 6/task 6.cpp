#include <iostream>
/*.����� ���������� ����� � ����������� ����������� �������, �������
������������ ����� � ���� int.�������� ��� � = 37 ���������� ����� 111.*/
void find_min(int k) {
    int od = 1; //1, 11,111 ,...
    while (od<=111111111) {
        for (int i = 1; i <= 9; i++)
        {
            int result = od * i;
            if (result % k == 0) {
                std::cout << result;
                return;
            }
        }
        od = od * 10 + 1;
    } 
    std::cout << "not found";
}
int main()
{
    int k;
    std::cin >> k;
    find_min(k);
}

