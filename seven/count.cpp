#include <iostream>

int seven_count;    /* number of seven's in the data */
int data[5];        /* the data to count 3 and 7 in */
int three_count;    /* the number of threes in the data */

int main() {
    int index;  /* index into the data */
    void get_data(int data[]);

    seven_count = 0;
    three_count = 0;
    get_data(data);

    for (index = 1; index <= 5; ++index) {
        if (data[index] == 3)
            ++three_count;
        if (data[index] == 7)
	    ++seven_count;
    }
    std::cout << "Three's " << three_count << 
	    " Seven's " << seven_count << '\n';
    return (0);
}
/********************************************************
 * get_data -- get 5 numbers from the command line	*
 ********************************************************/
void get_data(int data[])
{
    std::cout << "Enter 5 numbers\n";
    std::cin >> data[1] >> data[2] >> data[3] >> data[4] >> data[5];
}
