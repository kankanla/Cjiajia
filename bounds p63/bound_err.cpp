#include <iostream>

const int N_PRIMES = 7;	// Number of primes
// The first few prime numbers
int primes[N_PRIMES] = {2, 3, 5, 7, 11, 13, 17};

int main()
{
    int index = 10;

    std::cout << "The tenth prime is " << primes[index] << '\n';
    return (0);
}
