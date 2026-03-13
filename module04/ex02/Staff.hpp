#ifndef STAFF_HPP
#define STAFF_HPP

#include "Person.hpp"

class Form;

class Staff : public Person
{
public:
	Staff(const std::string& name) : Person(name) {}

	void sign(Form* p_form);
};

#endif
