#include <iostream>

int main()
{
    short int i;

    // Works
    for (i = 0x80; i != 0; i = (i >> 1)) {
	std::cout << "i is " << std::hex << i << std::dec << '\n';
    }

    signed char ch;

    // Fails
    for (ch = 0x80; ch != 0; ch = (ch >> 1)) {
	std::cout << "ch is " << std::hex << 
	    static_cast<int>(ch) << std::dec << '\n';
    }
    return (0);
}
