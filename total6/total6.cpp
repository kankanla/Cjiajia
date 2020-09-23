#include <iostream>

int total;      // total of all the numbers 
int current;    // current value from the user 
int counter;    // for loop counter 

int main() {
    total = 0;
    for (counter = 0; counter < 5; ++counter) {
	std::cout << "Number? ";

	std::cin >> current;
        total += current;
    }
    std::cout << "The grand total is " << total << '\n';
    return (0);
}
