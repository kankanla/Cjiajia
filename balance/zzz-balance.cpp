#include <iostream>

/*
	balance_owed = 0 ではなく
	balance_owed == 0 です。

*/

int balance_owed;

int main(int argc, char const *argv[])
{
	std::cout << "Enter number of dollars owed:";
	std::cin >> balance_owed ;

	if (balance_owed == 0)
		std::cout << "You owe nothing.\n";
	else
		std::cout << "You owe " << balance_owed << "dollars.\n";
	return 0;
}