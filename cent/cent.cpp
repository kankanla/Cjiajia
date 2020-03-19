#include <iostream>
/*
 * This program produces a Celsius to Fahrenheit conversion
 *    chart for the numbers 0 to 100.
 *
 * Restrictions:
 *	This program deals with integers only, so the
 *	calculations may not be exact.
 */

// the current Celsius temperature we are working with 
int celsius;

int main() {
    for (celsius = 0; celsius <= 100; ++celsius);
	std::cout << "celsius: " << celsius << 
		" Fahrenheit: " << ((celsius * 9) / 5 + 32) << '\n';
    return (0);
}
