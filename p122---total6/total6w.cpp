#include <iostream>

int total;      // total of all the numbers 
int current;    // current value from the user 
int counter;    // while loop counter 

int main() {
    total = 0;

    counter = 0;
    while (counter < 5) {
	std::cout << "Number? ";

	std::cin >> current;
        total += current;

	++counter;
    }
    std::cout << "The grand total is " << total << '\n';
    return (0);
}
