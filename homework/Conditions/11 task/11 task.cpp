#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << " ������� ����� ������\n";
	int k;
	std::cin >> k;
	int n = k;
	while (n > 100) {
		n=n-100;
	}
	
	if (n  >= 5 && n <= 20) std::cout << "�� ����� " << k << " ������ � ����"; // �� 5 �� 20
	else
		if (n % 10 == 1) std::cout << "�� ����� " << k << " ���� � ����"; //
		else
			if (n % 10 >= 2 && n % 10 <= 4) std::cout << "�� ����� " << k << " ����� � ����"; //
			else
				if (n % 10 >= 5 && n % 10 <= 9 || n % 10 == 0) std::cout << "�� ����� " << k << " ������ � ����"; //
}

