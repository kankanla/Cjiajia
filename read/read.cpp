/********************************************************
 * read -- read in 100 numbers and sum them		*
 *							*
 * Usage:						*
 *	read 						*
 *							*
 * Numbers are in the file "numbers.dat"		*
 *							*
 * Warning: No check is made for a file with less than	*
 * 100 numbers in it.					*
 ********************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
    const int DATA_SIZE = 100;	// Number of items in the data
    int data_array[DATA_SIZE];	// The data
    std::ifstream data_file("numbers.dat"); // The input file
    int i;			// Loop counter

    if (data_file.bad()) {
	std::cerr << "Error: Could not open numbers.dat\n";
	exit (8);
    }

    for (i = 0; i < DATA_SIZE; ++i) {
	assert(i >= 0);
	assert(i < sizeof(data_array)/sizeof(data_array[0]));

	data_file >> data_array[i];
    }

    int total;	// Total of the numbers

    total = 0;
    for (i = 0; i < DATA_SIZE; ++i) {
	assert(i >= 0);
	assert(i < sizeof(data_array)/sizeof(data_array[0]));

	total += data_array[i];
    }

    std::cout << "Total of all the numbers is " << total << '\n';
    return (0);
}
