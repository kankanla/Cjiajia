#include <iostream>
#include <cstdlib>

/*
	#define
*/
#define XXX std::cout <<"error XXX\n";exit(8);
#define YYY std::cout <<"error YYY\n";;
#define ZZZ std::cout << 12+12 << '\n';

int main(int argc, char const *argv[])
{
	int value;
	value = -1;
	if (value < 0) {
		ZZZ;
		YYY;
		XXX;
	}
	std::cerr << "Cree \n";
	return 0;
}