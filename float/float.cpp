#include <iostream>
#include <iomanip>

int main()
{
    // two number to work with 
    float number1, number2;
    float result;               // result of calculation 
    int   counter;              // loop counter and accuracy check 

    number1 = 1.0;
    number2 = 1.0;
    counter = 0;

    while (number1 + number2 != number1) {
        ++counter;
        number2 = number2 / 10.0;
    }
    std::cout << std::setw(2) << counter << 
	" digits accuracy in calculations\n";

    number2 = 1.0;
    counter = 0;

    while (true) {
        result = number1 + number2;
        if (result == number1)
            break;
        ++counter;
        number2 = number2 / 10.0;
    }
    std::cout << std::setw(2) << counter << 
	" digits accuracy in storage\n";
    return (0);
}
