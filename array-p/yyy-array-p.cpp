#include <iostream>
#include <assert.h>
#include <iomanip>

/*
	ポインタ型については要再確認 2020/03/24
	std::hex 表示
	std::dec 表示
	assert の使用
	sizeof bit数確認
	reinterpret_cast  ポインタ型を他のポインタ型に強制的に変換します。
	static_cast  ある型からある型への暗黙の変換が存在する
	https://www.yunabe.jp/docs/cpp_casts.html
*/

const int ARRAY_SIZE = 10;
char array[ARRAY_SIZE] = "0123abc78";

int main(int argc, char const *argv[])
{
	int index;
	for (index = 0; index < ARRAY_SIZE; ++index) {
		std::cout << std::hex;
		// std::cout << array  + index << std::endl;
		assert(index >= 0);
		assert(index < sizeof(array) / sizeof(array[0]));
		std::cout <<
		          "&array[index] =0x" <<
		          reinterpret_cast<int>(&array[index]) <<
		          "(array+index) =0x" <<
		          reinterpret_cast<int>(array + index) <<
		          " array[index] =0x" <<
		          static_cast<int>(array[index]) << '\n',
		          std::cout << std::dec;
	}

	double d = 3.14;
	int i = static_cast<int>(d);
	std::cout << i << std::endl;

	//static_cast 多くの場合はstatic_castは省略することが可能です。
	double e = 3.14;
	int ei = e;
	std::cout << ei << std::endl;

}



// for (int i = 0; i < n; ++i)
// for (int i = 0; i < n; i++)
// どちらもよく見るforループですが、このように++i,
// i++が単独で現れ、式の値を使わない場合は動作に関して違いはありません。