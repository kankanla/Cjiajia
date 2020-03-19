#include <iostream>
#include <cstdlib>
#include <string>

int   g, l, h, c, n;

int main()
{
    while (true) {
        /*Not Really*/
        g = rand() % 100 + 1;
        l = 0;
        h = 100;
        c = 0;
        while (true) {
	    std::cout << "Bounds " << l << " - " << h << '\n';
	    std::cout << "Value[" << c << "]? ";
            ++c;
	    std::cin >> n;
            if (n == g)
                break;
            if (n < g)
                l = n;
            else
                h = n;
        }
	std::cout << "Bingo\n";
    }
    return (0);
}
