
#include <iostream>

int main()
{
	int a = 3;
	int b = 5;
	int c = 8;
	std::cout << "starting order " << a <<" " << b <<" " << c << "\n";
	int x;
	if (a > b) x = a;
	else x = b;
	if (c > x) x = c;
	std::cout << x;
	
	return 0;
}
