#include <iostream>

/*
	while
	if
	std::cin
*/

int result;
char oper_char;
int value;

int main(int argc, char const *argv[])
{
	result = 0;
	while (true) {
		std::cout << "Result: " << result << '\n';
		std::cout << "Enter operatior and number: ";

		std::cin >> oper_char >> value;

		if ((oper_char == 'q' || (oper_char == 'Q')))
			break;
		if (oper_char == '+') {
			result += value;
		} else if (oper_char == '-') {
			result -= value;
		} else if (oper_char == '/') {
			if (value == 0) {
				std::cout << "Error:Divide by zero\n";
				std::cout << "  operation ignored\n";

			} else
				result /= value;
		} else {
			std::cout << "Unknown operation " << oper_char << '\n';
		}


	}
	return 0;
}
