#include <iostream>
/*���� ����������� ����� n. ����������,
�������� �� ��� �������� ����� 2, � �������� ����� YES, 
���� �������� � ����� NO, ���� �� ��������.  */
int main()
{
	int n;
	
		while (true) {

			std::cin >> n;
			while (n % 2 == 0 && n != 0) 
				n = n / 2; //����� ����� �� 2 ����. ���������� ���
			if (n == 1)
				std::cout << "yes\n";
			else
				std::cout << "no\n";
		}
	return 0;
}

