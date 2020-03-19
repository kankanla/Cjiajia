#include <iostream>
#include <assert.h>

const int X_SIZE = 40; // size of array in the X direction 
const int Y_SIZE = 60; // size of the array in Y direction 
/*
 * We use X_SIZE/8 since we pack 8 bits per byte
 */
char graphics[X_SIZE / 8][Y_SIZE];   // the graphics data 

/********************************************************
 * set_bit -- set a bit in the graphics array.		*
 *							*
 * Parameters 						*
 *	x,y -- location of the bit.			*
 ********************************************************/
inline void set_bit(const int x,const int y)
{
    assert((x >= 0) && (x < X_SIZE));
    assert((y >= 0) && (y < Y_SIZE));
    graphics[(x)/8][y] |= static_cast<char>(0x80 >>((x)%8));
}

int main()
{
    int   loc;        // current location we are setting
    void  print_graphics(); // print the data

    for (loc = 0; loc < X_SIZE; ++loc)
        set_bit(loc, loc);

    print_graphics();
    return (0);
}
/********************************************************
 * print_graphics -- print the graphics bit array       *
 *              as a set of X and .'s.                  *
 ********************************************************/
void print_graphics()
{
    int x;     // current x BYTE 
    int y;     // current y location 
    int bit;   // bit we are testing in the current byte 

    for (y = 0; y < Y_SIZE; ++y) {

        // Loop for each byte in the array 
        for (x = 0; x < X_SIZE / 8; ++x) {

            // Handle each bit 
            for (bit = 0x80; bit > 0; bit = (bit >> 1)) {
		assert((x >= 0) && (x < (X_SIZE/8)));
		assert((y >= 0) && (y < Y_SIZE));

                if ((graphics[x][y] & bit) != 0)
                    std::cout << 'X';
                else
                    std::cout << '.';
            }
        }
	std::cout << '\n';
    }
}
