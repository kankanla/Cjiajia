#include <iostream>
#include <assert.h>
#include <iomanip>

/*
	std::hex 表示
	std::dec 表示
	assert の使用
	sizeof bit数確認
	reinterpret_cast
	static_cast
*/

const int ARRAY_SIZE = 10;
char array[ARRAY_SIZE] = "012345678";
int main(int argc, char const *argv[])
{
	int index;
	for (index = 0; index < ARRAY_SIZE; ++index) {
		// std::cout << std::hex;
		assert(index >= 0);
		assert( index < sizeof(array) / sizeof(array[0]));
		std::cout <<
		          "&array[index] =0x " << 
		          reinterpret_cast<int>(&array[index]) <<
		          "(array+index) =0x " <<
		          reinterpret_cast<int>(array + index) <<
		          " array[index] =0x" <<
		          static_cast<int>(array[index]) << '\n',
		          std::cout << std::dec;
	}
}