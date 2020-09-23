#include <iostream>
#include <fstream>
#include <string>

std::ofstream save_file;	// Save input in this file 
int save_file_open = 0;	 	// Save file has been opened
std::ifstream playback_file;	// Playback data from this file 
int playback_file_open = 0;	// Playback file open flag
/********************************************************
 * extended_getline -- get a line from the input file	*
 *		and record it in a save file if needed	*
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
    if (playback_file_open) {
	std::getline(playback_file, line);
	if (file == std::cin) 
	    // echo the input to the standard out 
	    // so the user sees it 
	    std::cout << line << '\n';
    } else
	std::getline(file, line);

    // did someone ask for a save file 
    if (save_file_open) 
	save_file << line << '\n';

    return (file);
}
