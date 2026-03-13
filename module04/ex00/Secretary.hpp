#ifndef SECRETARY_HPP
#define SECRETARY_HPP

#include "Staff.hpp"

class Secretary : public Staff
{
public:
	Form* createForm(FormType p_formType);
	void archiveForm();
};

#endif
