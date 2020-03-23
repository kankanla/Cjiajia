//OK


#include <iostream>

int main()
{
    int i1, i2; // two random integers 

    i1 = 4;
    i2 = 2;     // set values 

    // Nice way of writing the conditional 
    if ((i1 != 0) && (i2 != 0))
        std::cout << "Both are not zero #1\n";

    // Shorthand way of doing the same thing 
    // Correct C++ code, but rotten style 
    if (i1 && i2)
        std::cout << "Both are not zero #2\n";

    // Incorrect use of bitwise and resulting in an error 
    if (i1 & i2)
        std::cout << "Both are not zero #3\n";
    return (0);
}
