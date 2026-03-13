#include "Headmaster.hpp"
#include "Secretary.hpp"
#include "Singletons.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include <iostream>

Form* Headmaster::requestForm(FormType type) {
    Form* f = nullptr;
    if (_secretary) {
        f = _secretary->createForm(type);
        if (f)
            receiveForm(f);
    }
    return f;
}

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

void Headmaster::requireProfessors() {
    for (size_t i = 0; i < Singletons<Professor>::getInstance().size(); ++i) {
        Professor* prof = Singletons<Professor>::getInstance().get(i);
        if (prof) {
            prof->doClass();
        }
    }
}

void Headmaster::ringBell()
{
    auto& students = Singletons<Student>::getInstance();
    auto& professors = Singletons<Professor>::getInstance();

    if (!_paused)
        std::cout << "RINGGGGGGGG : takes a break now !\n";
    else
        std::cout << "RINGGGGGGGG : return to work now !\n";
    
    for (size_t i = 0; i < students.size(); ++i)
        students.get(i)->update(Event::RingBell, _paused);

    for (size_t i = 0; i < professors.size(); ++i)
    professors.get(i)->update(Event::RingBell, _paused);

    _paused = !_paused;
}