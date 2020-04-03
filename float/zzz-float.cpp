#include <iostream>
#include <iomanip>

/*
	std::setw(int) 2 では変化がない
	number1 + number2 != number1
	result == number1
	の違い
*/

int main(int argc, char const *argv[])
{
	float number1, number2;
	float result;
	int counter;

	number1 = 1.0;
	number2 = 1.0;
	counter = 0;
	result = 0;

	// while (number1 + number2 != number1) {
	while (number1 + number2 != number1) {
		++counter;
		number2 = number2 / 10.0;
		std::cout << number2 << std::endl;
	}
	std::cout << std::setw(5) << counter << " digits accuracy in calculation \n";
	std::cout << std::setw(3) << counter << " digits accuracy in calculation \n";

	number2 = 1.0;
	counter = 0;

	while (true) {
		result = number1 + number2;
		if (result == number1) {
			break;
		}
		++counter;
		number2 = number2 / 10.0;
		std::cout << number2 << std::endl;
	}

	std::cout << std::setw(3) << counter << " digits accuracy in calculation \n";

	number2 = 1.0;
	counter = 0;

	while (true) {
		result = number1 + number2;
		if ((number1 + number2) == number1) {
			break;
		}
		++counter;
		number2 = number2 / 10.0;
		std::cout << number2 << std::endl;
	}



	std::cout << std::setw(3) << counter << " digits accuracy in calculation \n";

	return 0;
}