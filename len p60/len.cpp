#include <string>
#include <iostream>

std::string line;	// A line of data

int main()
{
    std::cout << "Enter a line:";
    std::getline(std::cin, line);

    std::cout << "The length of the line is: " << line.length() << '\n';
    return (0);
}
