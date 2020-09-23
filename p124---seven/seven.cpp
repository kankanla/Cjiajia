#include <iostream>

int seven_count;    // number of sevens in the data
int data[5];        // the data to count 3 and 7 in 
int three_count;    // the number of threes in the data 
int the_index; 	    // index into the data 

int main() {
    seven_count = 0;
    three_count = 0;

    std::cout << "Enter 5 numbers\n";
    std::cin >> data[1] >> data[2] >> data[3] >>
           data[4] >> data[5];

    for (the_index = 1; the_index <= 5; ++the_index) {

        if (data[the_index] == 3)
            ++three_count;

        if (data[the_index] == 7)
	    ++seven_count;
    }
    std::cout << "Threes " << three_count << 
	" Sevens " << seven_count << '\n';
    return (0);
}
