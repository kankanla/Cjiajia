#include <iostream>

int   result;    // the result of the calculations 
char  oper_char; // operator the user specified 
int   value;     // value specified after the operator

int main()
{
    result = 0; // initialize the result 

    // Loop forever (or till we hit the break statement) 
    while (true) {
	std::cout << "Result: " << result << '\n';

	std::cout << "Enter operator and number: ";
	std::cin >> oper_char >> value;

        if (oper_char = '+') {
            result += value;
        } else {
	    std::cout << "Unknown operator " << oper_char << '\n';
        }
    }
    return (0);
}
