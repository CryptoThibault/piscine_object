#ifndef SECRETARY_HPP
#define SECRETARY_HPP

#include "Staff.hpp"
#include "Headmaster.hpp"
#include "Form.hpp"
#include "Room.hpp"
#include <vector>

class SecretarialOffice : public Room
{
private:
	std::vector<Form*> _archivedForms;

public:
	SecretarialOffice() : Room(0) {}
	void archiveForm(Form* f) { if (f) _archivedForms.push_back(f); }
	const std::vector<Form*>& getArchivedForms() const { return _archivedForms; }
};

class Secretary : public Staff
{
public:
	Secretary(const std::string& name) : Staff(name) {}

	Form* createForm(FormType p_formType);
	void setCourseFinishedForm(Form* f, Course* course);
	void setNeedMoreClassRoomForm(Form* f, long long roomId);
	void setNeedCourseCreationForm(Form* f, std::string name, Professor* prof, int numClass, int maxStudents);
	void setSubscriptionToCourseForm(Form* f, Student* student, Course* course);
	void archiveForm(Form* f);
};

#endif
