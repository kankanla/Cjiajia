#include <iostream>
#include <fstream>
#include <string>

/*
 * The main program will open this file if -S is on 
 * the command line.
 */
std::ofstream save_file;	// File to use for saving input
int save_file_open = 0;		// Save file defaults to not open
/********************************************************
 * extended_getline -- get a line from the input file	*
 *		and record it in a save file if needed.	*
 *							*
 * Parameters						*
 *	file -- file to read data from			*
 *	line -- the line to read			*
 *							*
 * Returns						*
 * 	file -- (just like getline)			*
 ********************************************************/
std::istream& extended_getline(std::istream& file, std::string& line)
{
    std::getline(file, line);

    // did someone ask for a save file?
    if (save_file_open) {
	save_file << line << '\n';
    }

    return (file);
}
