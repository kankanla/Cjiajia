#include <iostream>

//論理演算子 && || !
//ビット演算子 & | ~ ^


int main(int argc, char const *argv[])
{
	int i1, i2, bit1;
	i1 = 4;
	i2 = 2;

	if ((i1 != 0) && (i2 != 0))
		std::cout << "Both are ont zero #1 \n";
	if ( i1 && i2)
		std::cout << "Both are not zero #2 \n";
	if (i1 & i2 )
		std::cout << "Both are not zero #3 \n";

	bit1 = i2 | i1;
	std::cout << bit1 << std::endl;

	return 0;
}