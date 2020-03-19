#include <iostream>

int   balance_owed;     // amount owed 

int main()
{
    std::cout << "Enter number of dollars owed:";
    std::cin >> balance_owed;

    if (balance_owed = 0)
        std::cout << "You owe nothing.\n";
    else
        std::cout << "You owe " << balance_owed << " dollars.\n";

    return (0);
}
