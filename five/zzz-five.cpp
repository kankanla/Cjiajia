#include <iostream>

float data[5];
float total;
float average;

/*
	20203433
*/

int main(int argc, char const *argv[])
{

	std::cout << data << '\n' << total << '\n' << average << '\n' << std::endl;

	data[0] = 34.0;
	data[1] = 27.0;
	data[2] = 46.5;
	data[3] = 82.0;
	data[4] = 22.0;

	total = data[0] + data[1] + data[2] + data[3] + data[4];
	average = total / 5.0;
	std::cout << "Total " << total << " Average " << average << '\n';

	std::cout << "--for----\n";
	total = 0;
	average = 0;
	for (int i = 0; i < (sizeof(data) / sizeof(data[0]))  ; i++) {
		total = total + data[i];
	}
	average = total / 5.0;
	std::cout << "Total " << total << " Average " << average << '\n';
	return 0;
}