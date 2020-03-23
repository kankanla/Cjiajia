#include <assert.h>
#include <iostream>
#include <iomanip>

const int ARRAY_SIZE  = 10; // Number of characters in array
// Array to print
char array[ARRAY_SIZE] = "012345678";
int main()
{
	int index;	/* Index into the array */
	for (index = 0; index < ARRAY_SIZE; ++index) {
		std::cout << std::hex;	// Trick to print hex numbers
		assert(index >= 0);
		assert(index < sizeof(array) / sizeof(array[0]));
		std::cout <<
		          "&array[index]=0x" <<
		          reinterpret_cast<int>(&array[index]) <<
		          " (array+index)=0x" <<
		          reinterpret_cast<int>(array + index) <<
		          " array[index]=0x" <<
		          static_cast<int>(array[index]) << '\n',
		          std::cout << std::dec;	// Another trick to go back to decimal
	}
	return (0);
}
