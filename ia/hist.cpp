/********************************************************
 * hist -- generate a histogram of an array of numbers  *
 *                                                      *
 * Usage                                                *
 *      hist <file>                                     *
 *                                                      *
 * Where                                                *
 *      file is the name of the file to work on         *
 ********************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>	
#include <assert.h>

#include "ia.h"

/*
 * the following definitions define the histogram
 */
const int NUMBER_OF_LINES = 50;	// # Lines in the result
const int LOW_BOUND       = 0;	// Lowest number we record
const int HIGH_BOUND      = 99;	// Highest number we record
/*
 * if we have NUMBER_OF_LINES data to 
 * output then each item must use
 * the following factor
 */
const int FACTOR = 
  ((HIGH_BOUND - LOW_BOUND +1) / NUMBER_OF_LINES);

// number of characters wide to make the histogram 
const int WIDTH = 60;

// Array to store the data in
static infinite_array data_array;
// Number if items in the array
static int data_items;

int main(int argc, char *argv[])
{
    void  read_data(const char *const name);// get the data into the array 
    void  print_histogram();// print the data 

    if (argc != 2) {
	std::cerr << "Error:Wrong number of arguments\n";
	std::cerr << "Usage is:\n";
	std::cerr << "  hist <data-file>\n";
	exit(8);
    }
    data_items = 0;

    read_data(argv[1]);
    print_histogram();
    return (0);
}
/********************************************************
 * read_data -- read data from the input file into      *
 *              the data_array.                         *
 *                                                      *
 * Parameters                                           *
 *      name -- the name of the file to read            *
 ********************************************************/
void  read_data(const char *const name)
{
    std::ifstream in_file(name); // input file 
    int data;	            // data from input 

    if (in_file.bad()) {
	std::cerr << "Error:Unable to open " << name << '\n';
	exit(8);
    }
    while (!in_file.eof()) {
	in_file >> data;

	// If we get an eof we ran out of data in last read
	if (in_file.eof())
	   break;

	// No assert needed becuase data_array is an ia
 	data_array[data_items] = data;
	++data_items;
    }
}
/********************************************************
 * print_histogram -- print the histogram output.       *
 ********************************************************/
void  print_histogram()
{
    // upper bound for printout 
    int   counters[NUMBER_OF_LINES];	
    int low;	   	// lower bound for printout 
    int   out_of_range = 0;// number of items out of bounds 
    int   max_count = 0;// biggest counter 
    float scale;   	// scale for outputting dots 
    int   index;   	// index into the data 

    memset(counters, '\0', sizeof(counters));

    for (index = 0; index < data_items; ++index) {
	int data;// data for this point 

	data = data_array[index];

	if ((data < LOW_BOUND) || (data > HIGH_BOUND))
	    ++out_of_range;
	else {
	    // index into counters array 
	    int   count_index;

	    count_index = static_cast<int>(
		    static_cast<float>(data - LOW_BOUND) / FACTOR);

	    assert(count_index >= 0);
	    assert(count_index < sizeof(counters)/sizeof(counters[0]));
	    ++counters[count_index];
	    if (counters[count_index] > max_count)
		max_count = counters[count_index];
	}
    }

    scale = float(max_count) / float(WIDTH);

    low = LOW_BOUND;

    for (index = 0; index < NUMBER_OF_LINES; ++index) {
	// index for outputting the dots 
	int   char_index;
	int   number_of_dots;	// number of * to output 

	std::cout << std::setw(2) << index << ' ' <<
		std::setw(3) << low << "-" << 
		std::setw(3) << (low + FACTOR -1) << " (" << 
		std::setw(4) << counters[index] << "): ";

	number_of_dots = int(float(counters[index]) / scale);
	for (char_index = 0; char_index < number_of_dots;
	     ++char_index)
	    std::cout << '*';
	std::cout << '\n';
	low += FACTOR;
    }
    std::cout << out_of_range << " items out of range\n";
}
