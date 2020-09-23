#include <iostream>

/* number of times through the loop */
extern int counter;

/* routine to increment the counter */
extern void inc_counter();

int main()
{
    int   index; /* loop index */

    for (index = 0; index < 10; ++index)
        inc_counter();
    std::cout << "Counter is " << counter << '\n';
    return (0);
}
