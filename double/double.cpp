#include <iostream>

int   value;	   // a value to double

int main()
{
    std::cout << "Enter a value: ";
    std::cin >> value;
    std::cout << "Twice " << value << " is " << value * 2 << '\n';
    return (0);
}
