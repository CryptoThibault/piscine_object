#ifndef HEADMASTER_HPP
#define HEADMASTER_HPP

#include <vector>
#include "Staff.hpp"
#include "Form.hpp"
#include "Room.hpp"

class Secretary;

class HeadmasterOffice : public Room {};

class Headmaster : public Staff
{
private:
	Secretary* _secretary;
	std::vector<Form*> _formToValidate;

public:
	Headmaster(const std::string& name, Secretary* secretary) : Staff(name), _secretary(secretary) {}
	
	Form* requestForm(FormType type);
	void receiveForm(Form* p_form);
	void validate(Form* f);
	bool hasForm(Form* f) const;
	void requireProfessors();
};

#endif
