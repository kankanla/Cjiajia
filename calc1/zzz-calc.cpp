#include <iostream>

int result;
char oper_char;
int value;

int main(int argc, char const *argv[])
{
	while(true){
		std::cout << "Result:" << result << '\n';
		std::cout << "Enter operatior and number";
		std::cin >> oper_char >> value;

		if('+' == oper_char){
			result += value;
		}else{
			std::cout << "Unknown operation "  << oper_char << '\n';
		}
	}
	return 0;
}


