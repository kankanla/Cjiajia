#include <iostream>
#include <cstdlib>

int main() {     
    int value;  // a random value for testing 
    
    value = 1; 
    if (value < 0) 
        std::cout << "Fatal Error:Abort\n";

    exit(8); 

    std::cout << "We did not die\n";
    return (0);
} 
