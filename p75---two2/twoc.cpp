#include <iostream>

signed char ch;	// Very short integer 
		// Range is -128 to 127

int main()
{
    std::cout << "The number is " << static_cast<int>(ch) << '\n';	
    return (0);
}
