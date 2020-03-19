
/********************************************************
 * DataBase -- A very simple database program that	*
 *		lookup names in a hardcoded list.	*
 * 							*
 * Usage:						*
 *	database [-S<file>]				*
 *							*
 *	-S<file>	Specify save file for 		*
 *			debugging purposes		*
 *							*
 *	-P<file>	Specify playback file for	*
 *			debugging or demonstration.	*
 *							*
 *		Program will ask you for a name.	*
 *		Enter the name; it will tell you if	*
 *		it is the list.				*
 *							*
 *		A blank name terminates the program.	*
 ********************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>

std::ifstream save_file;	// Save file if any 
int save_file_open = 0;         // Save file open flag
std::ofstream playback_file;	// Playback data
int playback_file_open = 0;     // True if playback in progress

// This should be in a header file
extern std::istream& extended_getline(std::istream& file, std::string line);

int main(int argc, char *argv[])
{
    std::string name;	// a name to lookup 
    char *save_file_name; // Name of the save file 
    char *playback_file_name; // Name of the playback file 

    bool lookup(const std::string& name);// lookup a name 

    while ((argc > 1) && (argv[1][0] == '-')) {
	switch (argv[1][1]) {
	    case 'S':
		save_file_name = &argv[1][2];
		save_file.open(save_file_name, std::ios::out);
		if (save_file.bad())
		    std::cerr << "Warning:Unable to open save file " <<
			    save_file_name << '\n';
		else
		    save_file_open = 1;
		break;
	    case 'P':
		playback_file_name = &argv[1][2];
		playback_file.open(playback_file_name, std::ios::in);
		if (playback_file.bad()) {
		    std::cerr <<
			"Error:Unable to open playback file " << 
			playback_file_name << '\n';
		    exit (8);
		} 
		playback_file_open = 1;
		break;
	    default:
		std::cerr << "Bad option: " << argv[1] << '\n';
		exit (8);
	}
	--argc;
	++argv;
    }    


    while (true) {
	std::cout << "Enter name: ";
	extended_getline(std::cin, name);

	/* ... rest of program ... */
   }
   return (0);
}
