#include <iostream>
/* ����� ����������� ����� �� ��������� �� a �� b � ������������ ������
���������.*/
void max_sum_del(int a,int b) {
	int i = a;
	int max_sum = 1;
	int max_num;
	while (i <= b) {// ������� ����� �� � �� �
		int sum = 0;
		int d = 1;
		while (d < i) {// ���������� ����� ���������
			if (i % d == 0) sum+= d;
			d++;
		}
		if (max_sum < sum) max_sum = sum , max_num = i;;
		i++;
	}
	std::cout << max_num;
}


int main()
{
	int a;
	int b;
	std::cin >> a >> b;
	max_sum_del(a, b);
    
}

