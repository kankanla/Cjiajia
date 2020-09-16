#include<iostream>

int main(int argc, char const *argv[])
{
	unsigned int bx = 0L;
	unsigned int bx2 = 0L;
	unsigned int  x = 0;

	bx = 4294967295 ;

	x = bx / 256;
	bx2 = 256 * 256 * 256 * 255;
	std::cout << bx << std::endl;
	std::cout << x << std::endl;
	std::cout << bx2 << std::endl;
	return 0;
}