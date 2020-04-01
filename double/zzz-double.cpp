#include <iostream>

int value;

int main(int argc, char const *argv[])
{
	std::cout << "Enter value: ";
	std::cin >>value;
	std::cout << "Twice " << value << " is " << value * 2 << '\n';
	return 0;
}