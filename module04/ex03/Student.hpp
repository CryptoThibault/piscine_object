#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <map>
#include "Person.hpp"

class Classroom;
class Course;
class Headmaster;
class Form;

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;
	std::map<Course*, int> _progress;

public:
	Student(const std::string& name) : Person(name) {}

	void addCourse(Course* course) { _subscribedCourse.push_back(course); }
	void removeCourse(Course* course);
	bool attendClass(Classroom* p_course);
	void exitClass();
	void graduate(Course* p_course);
	Form* requestCourseSubscription(Headmaster* headmaster, Course* course);

	std::vector<Course*> getSubscribedCourses() const { return _subscribedCourse; }
	int getProgress(Course* course) const {
		auto it = _progress.find(course);
		return it != _progress.end() ? it->second : 0;
	}
};

#endif
