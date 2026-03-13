#ifndef HEADMASTER_HPP
#define HEADMASTER_HPP

#include <vector>
#include "Staff.hpp"
#include "Form.hpp"

class Headmaster : public Staff
{
private:
	std::vector<Form*> _formToValidate;
	
public:
	Headmaster(const std::string& name) : Staff(name) {}

	void receiveForm(Form* p_form);
	void validate(Form* f);
	bool hasForm(Form* f) const;
};

#endif
