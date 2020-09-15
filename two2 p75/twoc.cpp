#include <iostream>

signed char ch;

int main(int argc, char const *argv[])
{
	ch = 37;
	for (int i = 0 ; i < 10 ; ++i) {
		std::cout << "The number is " << static_cast<int>(ch) << "\n";
		std::cout << "The number is " << (ch) << "\n";
		++ch;
	}
	return 0;
}