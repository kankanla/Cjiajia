#include <iostream>
#include <cstring>

char name[30];	// First name of someone

int main()
{
    std::strcpy(name, "Sam");
    std::cout << "The name is " << name << '\n';
    return (0);
}
