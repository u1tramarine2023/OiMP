

#include <iostream>

int main()
{
	int a = 4;
	int b = 7;
	if (a > b)
	{
		std::cout << "yes\n";
	}
	else
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
		std::cout << "a=" << a << " b=" << b;
	}
	return 0;
}
