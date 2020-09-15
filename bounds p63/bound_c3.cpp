#include <iostream>
#include <assert.h>

#define LIMIT_CHECK(array, index) 		\
    do {					\
	assert((index) < 			\
	    (sizeof(array)/sizeof(array[0])));	\
	assert((index) >= 0);			\
    } while (0);

// The first few prime numbers
int primes[] = {2, 3, 5, 7, 11, 13, 17};

int main()
{
    int index = 10;

    LIMIT_CHECK(primes, index);
    std::cout << "The tenth prime is " << primes[index] << '\n';
    return (0);
}
