#include "Course.hpp"

void Course::subscribe(Student* p_student) { 
    if (static_cast<int>(_students.size()) >= _maximumNumberOfStudent)
        return;
    _students.push_back(p_student);
}

void Course::unsubscribe(Student* p_student) {
    for (auto it = _students.begin(); it != _students.end(); ++it)
        if (*it == p_student) {
            _students.erase(it);
            return;
        }
}