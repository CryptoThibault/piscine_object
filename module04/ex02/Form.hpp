#ifndef FORM_HPP
#define FORM_HPP

#include "Course.hpp"
#include "Professor.hpp"

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form
{
private:
	FormType _formType;
	bool _validated;

public:
	Form(FormType p_formType) : _formType(p_formType), _validated(false) {}
	virtual ~Form() {}


	virtual void execute() = 0;
	
	FormType getType() const { return _formType; }
	bool isValidated() { return _validated; }
	void setValidated(bool v) { _validated = v; }
};

class CourseFinishedForm : public Form
{
private:
	Course* _course;
public:
	CourseFinishedForm() : Form(FormType::CourseFinished), _course(nullptr) {}

	void execute();
	void setCourse(Course* course) { _course = course; }
};

class NeedMoreClassRoomForm : public Form
{
private:
	long long _roomId;
public:
	NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom), _roomId(0) {}

	void execute();
	void setRoomId(long long id) { _roomId = id; }
};

class NeedCourseCreationForm : public Form
{
private:
	std::string _courseName;
	Professor* _professor;
	int _numClass;
	int _maxStudents;
public:
	NeedCourseCreationForm() : Form(FormType::NeedCourseCreation), _courseName(""), _professor(nullptr), _numClass(0), _maxStudents(0) {}

	void execute();
	void setCourseDetails(std::string name, Professor* prof, int numClass, int maxStudents) {
		_courseName = name;
		_professor = prof;
		_numClass = numClass;
		_maxStudents = maxStudents;
	}
};

class SubscriptionToCourseForm : public Form
{
private:
	Student* _student;
	Course* _course;
public:
	SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse), _student(nullptr), _course(nullptr) {}

	void execute();
	void setSubscriptionDetails(Student* student, Course* course) {
		_student = student;
		_course = course;
	}
};

#endif
