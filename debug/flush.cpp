#include <iostream>
int main()
{
    int i,j;	/* two random integers */

    i = 1;
    j = 0;
    std::cout << "Starting\n";
    std::cout << "Before divide...";
    i = i / j;	// divide by zero error 
    std::cout << "After\n";
    return(0);
}
