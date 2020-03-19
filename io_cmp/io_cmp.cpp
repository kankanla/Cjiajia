/********************************************************
 * small program to print the same string using C++ and	*
 * C formatted output.  Although this shows that the C	*
 * version is simpler, it does not take into account	*
 * properly object design where the object knows how	*
 * to print itself.					*
 ********************************************************/
#include <string>
#include <iostream>
#include <iomanip>

#include <cstdio>

struct date_t {
    int month;
    int day;
    int year;
};
struct check_t {
    int number;
    char payee[61];
    float amount;
};

date_t date = {10, 5, 01};
check_t check = {123, "Bookstore", 12.34};


int main()
{
    printf("%2d/%2d/%02d %4d: %-40s %6.2f\n",
	    date.month, date.day, date.year,
	    check.number, check.payee, check.amount);

    cout << setw(2) << date.month << '/' << 
	setw(2) << date.day << '/' <<
	setw(2) << setfill('0') << date.year << setfill(' ') << ' ' << 
	setw(4) << check.number << ": " <<
	setw(40) << setiosflags(ios::left) << check.payee <<
	resetiosflags(ios::left) << ' ' <<
	setw(6) << setprecision(2) << setiosflags(ios::fixed) << 
	check.amount <<
	setw(0) << '\n';
    return (0);
}
