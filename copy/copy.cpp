#include <cstdio>
#include <cstdlib>	/* ANSI Standard C file */
#include <iostream>

const char FILE_NAME[] = "input.txt";	// Name of the input file

int main()
{
    int  count = 0;  // number of characters seen 
    std::FILE *in_file;   // input file 

    int ch;          // character or EOF flag from input 

    in_file = std::fopen(FILE_NAME, "rb");
    if (in_file == NULL) {
	std::cerr << "Can not open " << FILE_NAME << '\n';
        exit(8);
    }

    while (true) {
        ch = std::fgetc(in_file);
        if (ch == EOF)
            break;
        ++count;
    }
    std::cout << "Number of characters in " << FILE_NAME << 
	" is " << count << '\n';

    std::fclose(in_file);
    return (0);
}
