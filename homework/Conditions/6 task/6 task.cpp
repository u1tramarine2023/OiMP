#include <iostream>
/*6. Даны три числа. Написать "yes", если можно взять какие-то два из них и в сумме получить третье  */
int main()
{
	int a = 3;
	int b = 2;
	int c = 5;
	if (a + b == c || a + c == b || b + c == a) std::cout << "yes";

}
