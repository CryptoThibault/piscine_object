#include "Headmaster.hpp"

void Headmaster::receiveForm(Form* p_form) {
		_formToValidate.push_back(p_form);
	}

void Headmaster::validate(Form* f) {
		if (hasForm(f))
			f->setValidated(true);
}

bool Headmaster::hasForm(Form* f) const {
    if (!f) return false;
    for (size_t i = 0; i < _formToValidate.size(); ++i)
        if (_formToValidate[i] == f)
            return true;
    return false;
}
