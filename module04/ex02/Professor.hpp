#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Staff.hpp"
#include "Course.hpp"
#include <iostream>

class Professor : public Staff
{
private:
	Course* _currentCourse;

public:
	Professor(const std::string& name) : Staff(name) {}
	void assignCourse(Course* p_course) { _currentCourse = p_course; }
	void doClass();
	void closeCourse() { std::cout << "Professor " << getName() << " closes the course." << std::endl; }
};
#endif
