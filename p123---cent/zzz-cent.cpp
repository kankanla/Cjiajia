#include <iostream>

/*
	for (c = 0; c <= 100; ++c);
	ではなく
	for (c = 0; c <= 100; ++c) {
	}
	です。
*/

int c;

int main(int argc, char const *argv[])
{
	for (c = 0; c <= 100; ++c) {
		std::cout << c << '\n';
	}
	return 0;
}