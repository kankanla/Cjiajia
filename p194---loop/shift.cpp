#include <iostream>

int main(int argc, char const *argv[])
{
	int v = 0x1;
	int b;
	for (int i = 0; i < 10000; ++i) {
		b=rand();
		v = v < 10;
		std::cout << "\r" << b ;
	}
	return 0;
}