/********************************************************
 * class_stuff -- A simple class to handle students	*
 * and grades.						*
 ********************************************************/
#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <list>

#include <algorithm>

const unsigned int MAX_STUDENTS = 5;	// Max number of students per class
// Set low for testing

class class_stuff {
    public:	
	typedef vector<int> grades;	// A set of grades

	map<string, grades> roster;	// Roster of current class
	list<string> waiting_list;	// People waiting on the list
    public:
	// Constructor defaults
	// Destructor defaults
	// Copy constructor defaults
	// Assignment operator
    public:
	void add_student(const string& name);
	void drop_student(const string& name);
	void record_grade(const string& name, 
		const int grade,
		const unsigned int assignment_number
	);
	void print_grades();
    private:
	// Insert a student into the class
	void new_student(
	    const string& name	// Student to add to the class
	)
	{
	    grades no_grades;	// Empty grade vector
	    roster.insert(pair<string, grades>(name, no_grades));
	}
};

/********************************************************
 * class_stuff::add_student -- Add a student to a class	*
 * 	If the class if full, add him to the waiting 	*
 * 	list.						*
 *********************************************************/
void class_stuff::add_student(
    const string& name	// Name of the student to add
)
{
    if (roster.find(name) != roster.end())
	return;	// Already in the class, don't reuse

    if (roster.size() < MAX_STUDENTS) {
	// Class has room, add to class
	new_student(name);
    } else {
	// No room, put on waiting list
	waiting_list.push_back(name);
    }
}
/********************************************************
 * class_stuff::drop_student -- Remove student from 	*
 * a class.  If there's a waiting list his place is	*
 * filled by the first student on the list.		*
 ********************************************************/
void class_stuff::drop_student(
    const string& name	// Name of the student to drop
)
{
    // The student we are probably going to drop
    map<string, grades>::iterator the_student =
	roster.find(roster.begin(), roster.end(), roster);

    if (the_student == roster.end())
	return;	// Student is not in the class

    roster.erase(name);
    // Add a person from the waiting_list if 
    // there's anyone waiting
    if (waiting_list.size() > 0) {
	string wait_name = waiting_list.front();
	waiting_list.pop_front();
	new_student(wait_name);
    }
}

/********************************************************
 * class_stuff::record_grade -- Record a grade for 	*
 * 	a student.					*
 ********************************************************/
void class_stuff::record_grade(
    const string& name, 	// Name of the student
    const int grade,		// Grade of this assignment
    				// Assignment number
    const unsigned int assignment_number
)
{
    map<string, grades>::iterator the_student =
	roster.find(name);

    if (the_student == roster.end())
    {
	cerr << "ERROR: No such student " << name << '\n';
	return;
    }
    // Resize the grade list if there's not enough room
    if (the_student->second.size() <= assignment_number)
	the_student->second.resize(assignment_number+1);

    the_student->second[assignment_number] = grade;
}

/********************************************************
 * class_stuff::print_grades -- Print the students 	*
 * and their grades.					*
 ********************************************************/
void class_stuff::print_grades()
{
    vector<string> sorted_names;	// Student names sorted

    // The student we are inserting into the storted_names list
    map<string, grades>::iterator cur_student;

    for (cur_student = roster.begin();
	 cur_student != roster.end();
	 ++cur_student)
    {
	sorted_names.push_back(cur_student->first);
    }
    sort(sorted_names.begin(), sorted_names.end());

    // The current student to print
    vector<string>::const_iterator cur_print;

    for (cur_print = sorted_names.begin();
	 cur_print != sorted_names.end();
	 ++cur_print)
    {
	cout << *cur_print << '\t';

	// The grade we are printing now
	grades::const_iterator cur_grade;

	for (cur_grade = roster[*cur_print].begin();
	     cur_grade != roster[*cur_print].end();
	     ++cur_grade)
	{
	    cout << *cur_grade << ' ';
	}
	cout << '\n';
    }
}


int main()
{
    // A class for testing
    class_stuff test_class;

    test_class.add_student("Able, Sam");
    test_class.add_student("Baker, Mary");
    test_class.add_student("Johnson, Robin");
    test_class.add_student("Smith, Joe");
    test_class.add_student("Mouse, Micky");

    test_class.add_student("Gadot, Waiting");
    test_class.add_student("Congreve, William");

    cout << "Before drop " << endl;
    test_class.print_grades();
    cout << "\n";
    
    test_class.drop_student("Johnson, Robin");

    cout << "After drop " << endl;
    test_class.print_grades();
    cout << "\n";

    int i;

    for (i = 0; i < 5; ++i)
    {
	test_class.record_grade("Able, Sam",      i*10+50, i);
	test_class.record_grade("Baker, Mary",    i*10+50, i);
	test_class.record_grade("Smith, Joe",     i*10+50, i);
	test_class.record_grade("Mouse, Micky",   i*10+50, i);
	test_class.record_grade("Gadot, Waiting", i*10+50, i);
    }

    cout << "Final " << endl;
    test_class.print_grades();
    cout << "\n";

    return (0);
}
