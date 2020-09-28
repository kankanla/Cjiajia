/*
	すべてエラー
*/

#include <iostream>

#define BIG_NUMBER 10 ** 10
int main(int argc, char const *argv[])
{
	int index;
	index = 0;
	while (index < BIG_NUMBER) {
		index = index * 8;
	}
	std::cout << index << std::endl;
	return 0;
}