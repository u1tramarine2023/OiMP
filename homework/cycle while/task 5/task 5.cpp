#include <iostream>
// �� ������� ������������ ����� n ������� ����� ����� 1+1/1!+1/2!+1/3!+...+1/n!.
int main()
{
	int a, i, n;
	double result = 1;
	i = 1; //������� ��������
	std::cin >> n;
	while (i <= n) {
		double factorial = 1.;
		int k = 1; //������� ��� ����������
		while (k <= i) { //��������� ��� ������� ����� �����
			factorial /= k; // �.�. 1/(1*2*�)=1/2/�
			k++;
		}
		result += factorial;
		i++;
	}
	std::cout << result << "\n";
	return 0; //���������� � 2.71828
}


