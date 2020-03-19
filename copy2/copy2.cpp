/****************************************
 * copy -- copy one file to another.    *
 *                                      *
 * Usage                                *
 *      copy <from> <to>                *
 *                                      *
 * <from> -- the file to copy from      *
 * <to>   -- the file to copy into      *
 ****************************************/
#include <iostream>
#include <cstdlib>	

#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>

#ifdef __WIN32__        // if we are Windows32
#include <io.h>		// Get the Windows32 include file for raw i/o
#else /* __WIN32__ */
#include <unistd.h>	// Get the UNIX include file for raw i/o 
#endif /* __WIN32__ */

const int BUFFER_SIZE = (16 * 1024); // use 16k buffers 

int main(int argc, char *argv[])
{
    char  buffer[BUFFER_SIZE];  // buffer for data 
    int   in_file;              // input file descriptor
    int   out_file;             // output file descriptor 
    int   read_size;            // number of bytes on last read 

    if (argc != 3) {
	std::cerr << "Error:Wrong number of arguments\n";
	std::cerr << "Usage is: copy <from> <to>\n";
        exit(8);
    }
    in_file = open(argv[1], O_RDONLY);
    if (in_file < 0) {
	std::cerr << "Error:Unable to open " << argv[1] << '\n';
        exit(8);
    }
    out_file = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (out_file < 0) {
	std::cerr << "Error:Unable to open " << argv[2] << '\n';
        exit(8);
    }
    while (true) {
        read_size = read(in_file, buffer, sizeof(buffer));

        if (read_size == 0)
            break;              // end of file 

        if (read_size < 0) {
	    std::cerr << "Error:Read error\n";
            exit(8);
        }
        write(out_file, buffer, (unsigned int) read_size);
    }
    close(in_file);
    close(out_file);
    return (0);
}
