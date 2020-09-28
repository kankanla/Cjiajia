#include <iostream>

#define SIZE    10;
#define FUDGE   SIZE -2;

int main()
{
    int size;// size to really use 
    
    size = FUDGE;
    std::cout << "Size is " << size << '\n';
    return (0);
}
