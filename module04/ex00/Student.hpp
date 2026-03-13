#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <vector>
#include "Person.hpp"

class Classroom;
class Course;

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;

public:
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
};

#endif
