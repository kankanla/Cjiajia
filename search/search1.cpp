/********************************************************
 * search -- Search a set of numbers. 			*
 *							*
 * Usage:						*
 *	search						*
 *		you will be asked numbers to lookup	*
 *							*
 * Files:						*
 *	numbers.dat -- numbers 1 per line to search	*
 *			(Numbers must be ordered)	*
 ********************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <assert.h>

const int MAX_NUMBERS = 1000;	// Max numbers in file 
const char *const DATA_FILE = "numbers.dat";// File with numbers 

int data[MAX_NUMBERS];	// Array of numbers to search 
int max_count;		// Number of valid elements in data 
int main()
{
    std::ifstream in_file;	// Input file 
    int	middle;		// Middle of our search range 
    int low, high;	// Upper/lower bound 
    int search;		// number to search for 

    in_file.open(DATA_FILE, std::ios::in);
    if (in_file.bad()) {
	std::cerr << "Error:Unable to open " << DATA_FILE << '\n';
	exit (8);
    }

    /*
     * Read in data 
     */

    max_count = 0;

    while (true) {
	char line[30];	// Line from the input file

	if (in_file.eof())
	    break;

	in_file.getline(line, sizeof(line));

	assert(max_count >= 0);
	assert(max_count < sizeof(data)/sizeof(data[0]));
	std::sscanf(line, "%d", &data[max_count]);
	if (data[max_count] == -1)
	    break;

	++max_count;
    }

    while (true) {
	std::cout << "Enter number to search for or -1 to quit:" ;
	std::cin >> search;

	if (search == -1)
	    break;

	low = 0;
	high = max_count;

	while (true) {
	    middle = (low + high) / 2;

	    assert(middle >= 0);
	    assert(middle < sizeof(data)/sizeof(data[0]));
	    if (data[middle] == search) {
		std::cout << "Found at index " << middle << '\n';
	    }

	    if (low == high) {
		std::cout << "Not found\n";
		break;
	    }

	    assert(middle >= 0);
	    assert(middle < sizeof(data)/sizeof(data[0]));
	    if (data[middle] < search)
		low = middle;
	    else
		high = middle;
	}
   }
   return (0);
}
