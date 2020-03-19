#include <iostream>
int main()
{
    int i,j;	/* two random integers */

    i = 1;
    j = 0;
    std::cout << "Starting\n";
    std::cout.flush();
    std::cout << "Before divide...";
    std::cout.flush();
    i = i / j;	// divide by zero error 
    std::cout << "After\n";
    std::cout.flush();
    return(0);
}
