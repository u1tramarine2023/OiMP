
#include <iostream>
/* 3. Даны три числа. Найдите те два из них, сумма которых наибольшая.  */
int main()
{
	int a = 10;
	int b = 5;
	int c = 14;
	int m1;
	int m2;
	if (a > b)
	{
		m1 = a; m2 = b;
	}
	else {
		m1 = b; m2 = a;
	}

	if (c > m2) {
		if (c > m1) {
			m2 = m1;
			m1 = c;
		
		}
		else {
			m2 = c;
		}
	}
	std::cout << "Sum =" << m1 + m2;
	
	return 0;
}

