#include <iostream>
/* ��� ��������� N ����� ��� ������� ��� ����������� �����
(����������� ���������� �����, ������ ����� ���� ����� ���������, ��
������ ������ �����)*/
void deliteli(int n) {
	int i=1;
	while (i < n) { 
		int sum = 0;
		int d = 1;
		while (d < i) {
			if (i % d == 0) sum += d;
			d++;
		}
		if (i == sum) std::cout << i << " ";
		i++;
	}
}

int main()
{
	int n;
	std::cin >> n;
	deliteli(n) ;
}
