#include <iostream>
using namespace std;

class Course 
{
public:
	void virtual startClass() = 0;
};

class ProgrammingCourse : public Course 
{
public:
	void startClass() 
	{
		cout << "Programming class has started\n";
	}
};

class MathCourse : public Course 
{
public:
	void startClass() 
	{
		cout << "Math class has started\n";
	}
};

int main() 
{
	Course* course_pointer;
	ProgrammingCourse program_object;
	MathCourse math_object;

	course_pointer = &program_object;
	course_pointer->startClass();

	course_pointer = &math_object;
	course_pointer->startClass();

	return 0;
}
