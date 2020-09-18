#include<iostream>


/********************************************************
 * length -- compute the length of a string             *
 *                                                      *
 * Parameters                                           *
 *      string -- the string whose length we want       *
 *                                                      *
 * Returns                                              *
 *      the length of the string                        *
 ********************************************************/

int length(const char string[]) {
	int i;
	for (i = 0; string[i] != '\0'; ++i) {}
	return i;
}

int main(int argc, char const *argv[])
{
	int b = length("abc");
	std::cout << b << std::endl;
	return 0;
}


// int  length(char string[])
// {
// 	int index;      // index into the string

// 	/*
// 	 * Loop until we reach the end of string character
// 	 */
// 	for (index = 0; string[index] != '\0'; ++index)
// 	/* do nothing */
// 	return (index);
// }

// int main(int argc, char const *argv[])
// {
// 	/* code */

// 	int b = length("a");

// 	// return 0;
// }

