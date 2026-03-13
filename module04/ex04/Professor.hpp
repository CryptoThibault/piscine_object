#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <iostream>
#include "Staff.hpp"
#include "Course.hpp"
#include "Observer.hpp"

class Headmaster;
class Form;

class Professor : public Staff, public Observer
{
private:
	Course* _currentCourse;
	bool _paused;

public:
	Professor(const std::string& name) : Staff(name), _paused(false) {}

	Form* requestCourseCreation(const std::string& name, int numClass, int maxStudents);
	Form* requestStudentGraduation(Student* student, Course* course);
	void assignCourse(Course* p_course) { _currentCourse = p_course; }
	void doClass();
	void closeCourse() { std::cout << "Professor " << getName() << " closes the course." << std::endl; }

	Course* getCurrentCourse() const { return _currentCourse; }

	void update(Event e, bool pause)
	{
        if (e == Event::RingBell)
            _paused = !pause;
    }
	bool isPaused() const { return _paused; }
};
#endif
