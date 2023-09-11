
#include <iostream>
/* 5. Даны три числа. Написать "yes", если среди них есть одинаковые.  */
int main()
{
	int a = 10;
	int b = 5;
	int c = 5;
	if (a == b || a == c || b == c) std::cout << "yes";
	
	return 0;
}


