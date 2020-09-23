#include <string>
#include <iostream>

std::string first_name;	// First name of the author
std::string last_name;	// Last name of the author
std::string full_name;	// Full name of the author

int main()
{
    first_name = "Steve";
    last_name = "Oualline";
    full_name = first_name + " " + last_name;
    std::cout << "Full name is " << full_name << '\n';
    return (0);
}

