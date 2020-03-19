#include <iostream>

char char1;	// first character 
char char2;	// second character
char char3;	// third character 

int main()
{
    char1 = 'A';
    char2 = 'B';
    char3 = 'C';
    std::cout << char1 << char2 << char3 << " reversed is " <<
	    char3 << char2 << char1 << "\n";
    return (0);
}
