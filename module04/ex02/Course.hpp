#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <vector>

class Professor;
class Student;

class Course
{
private:
	std::string _name;
	Professor* _responsable;
	std::vector<Student*> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
public:
	Course(std::string p_name) : _name(p_name) {}

	void assign(Professor* p_professor) { _responsable = p_professor; }
	void subscribe(Student* p_student) { _students.push_back(p_student); }

	std::string getName() const { return _name; }
	Professor* getResponsable() const { return _responsable; }
	void setNumberOfClassToGraduate(int n) { _numberOfClassToGraduate = n; }
	void setMaximumNumberOfStudent(int n) { _maximumNumberOfStudent = n; }
};

#endif
