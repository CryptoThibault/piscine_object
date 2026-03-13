#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include "Person.hpp"

class Classroom;
class Course;

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;

public:
	Student(const std::string& name) : Person(name) {}

	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
};

#endif
