#include <iostream>

#define SQR(x) ((x) * (x))

int main()
{
    int counter;    /* counter for loop */

    counter = 0;
    while (counter < 5)
        std::cout << "x " << (counter+1) << 
		" x squared " << SQR(++counter) << '\n';
    return (0);
}
