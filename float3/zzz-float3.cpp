#include <iostream>

/*
	std::printf("The %f\n", re);
	flost の出力
*/

int main(int argc, char const *argv[])
{
	float re;
	re = 21.0 / 6.0;
	std::cout << re << std::endl;
	std::printf("The %d\n", re);
	std::printf("The %f\n", re);
	return 0;
}