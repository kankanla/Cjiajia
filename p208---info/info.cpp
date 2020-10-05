#include <iostream>

struct info {
    int valid:1;	// If 1, we are valid
    int data:31;	// The data
};

info a_info;

int main()
{
    a_info.valid = 1;
    if (a_info.valid == 1) 
	std::cout << "a_info is valid\n";
    return (0);
}
