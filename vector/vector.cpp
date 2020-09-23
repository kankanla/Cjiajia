/********************************************************
 * simple STL program.					*
 ********************************************************/
#include <iostream>
#include <vector>

int main()
{
    vector<int> number;	// Our list of numbers
    
    while (true)
    {
	std::cout << "Enter a number or -1 to end: ";

	int answer;	// Answer to our prompt
	std::cin >> answer;

	if (answer == -1)
	    break;

	number.push_back(answer);
    }

    int total = 0;	// Total of the number vector
    vector<int>::const_iterator cur_number;	// Current number

    for (cur_number = number.begin();
	 cur_number != number.end();
	 ++cur_number)
    {
	total += *cur_number;
    }
    std::cout << "Total is " << total << '\n';
    std::cout << "Average is " << 
	static_cast<double>(total) / static_cast<double>(number.size()) <<
	'\n';
    return (0);
}

