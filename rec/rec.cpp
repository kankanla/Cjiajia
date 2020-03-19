#include <iostream>

#define RECIPROCAL (number) (1.0 / (number))

int main()
{
    float   counter;

    for (counter = 0.0; counter < 10.0; 
	 counter += 1.0) {

	std::cout << "1/" << counter << " = " << 
		  RECIPROCAL(counter) << "\n"; 
    }
    return (0);
}
