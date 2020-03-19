#include <iostream>
#include <assert.h>

// The first few prime numbers
int primes[] = {2, 3, 5, 7, 11, 13, 17};

int main()
{
    int index = 10;

    assert(index < (sizeof(primes)/sizeof(primes[0])));
    assert(index >= 0);

    std::cout << "The tenth prime is " << primes[index] << '\n';
    return (0);
}
