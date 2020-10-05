#include <iostream>

int main(int argc, char const *argv[])
{
	int x = 256 * 256;
	std::cout << "int " << x << " de " << sizeof(x) << std::endl;
	char c = 'c';
	std::cout << "char " << c << " de " << sizeof(c) << std::endl;
	std::string  s = "aa";
	std::cout << "std::string " << s << " de " << sizeof(s) << std::endl;
	return 0;
}