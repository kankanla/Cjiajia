#include <iostream>

int   total;       // Running total of all numbers so far 
int   item;        // next item to add to the list
int   minus_items; // number of negative items 

int main()
{
    total = 0;
    minus_items = 0;
    while (true) {
	std::cout << "Enter # to add\n";
	std::cout << "  or 0 to stop:";
	std::cin >> item;

        if (item == 0)
            break;

        if (item < 0) {
            ++minus_items;
            continue;
        }
        total += item;
	std::cout << "Total: " << total << '\n';
    }

    std::cout << "Final total " << total << '\n';
    std::cout << "with " << minus_items << " negative items omitted\n";
    return (0);
}
