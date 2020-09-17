#include <iostream>
#include <assert.h>

int main(int argc, char const *argv[])
{
	int x , y;
	x = 2;
	y = 1;

	assert(x > 2);
	std::cout << "line1" << std::endl;
	std::cout << "line2" << std::endl;

	return 0;
}

//error
/*Assertion failed: x > 2, file C:\Users\kankanla\Desktop\Cjiajia\matrix\t1.cpp, line 10

This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.*/