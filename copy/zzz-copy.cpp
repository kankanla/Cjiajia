/*標準ライブラリヘッダ <cstdio>
 C++ 標準ライブラリヘッダ
このヘッダは元々 C 標準ライブラリに <stdio.h> として存在していました。
このヘッダは C スタイルの入出力ライブラリの一部です。 */
// #include <cstdio>
/*cstdlib とは、C++でC標準ライブラリ(stdlib)を使用するときにインクルードするヘッダファイルです。*/
// #include <cstdlib>
#include <iostream>

const char FILE_NAME[] = "input.txt";

/*
	std::FILE *in_file;
	in_file = std::fopen(FILE_NAME, "rb");
	std::fclose(in_file);
	正常終了 exit(0); main 関数から Exit
	異常終了 exit(1); main 関数から Exit
*/

int main(int argc, char const *argv[])
{
	int count = 0;
	std::FILE *in_file;
	int ch;

	in_file = std::fopen(FILE_NAME, "rb");
	if (in_file == NULL) {
		std::cerr << "Can not open" << FILE_NAME << '\n';
		exit(8);
	}

	while (true) {
		ch = std::fgetc(in_file);
		if (ch == EOF)
			break;
		std::cout << ch << std::endl;
		++count;
	}
	std::cout << "Number of characters in " << FILE_NAME << " is " << count << '\n';
	std::fclose(in_file);

	return 0;
}