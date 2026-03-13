#include "Student.hpp"
#include "Headmaster.hpp"
#include "Form.hpp"
#include "Room.hpp"

bool Student::attendClass(Classroom* p_classroom) {
    if (!p_classroom) return false;
    Course* course = p_classroom->getCurrentCourse();
    if (!course) return false;
    _progress[course]++;
    return _progress[course] >= course->getNumberOfClassToGraduate();
}

void Student::removeCourse(Course* course) {
    for (auto it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it) {
        if (*it == course) {
            _subscribedCourse.erase(it);
            return;
        }
    }
}

void Student::graduate(Course* p_course) {
    if (!p_course)
        return;
    p_course->unsubscribe(this);
    removeCourse(p_course);
}

Form* Student::requestCourseSubscription(Headmaster* headmaster, Course* course) {
    Form* form = nullptr;
    if (headmaster) {
        form = headmaster->requestForm(FormType::SubscriptionToCourse);
        SubscriptionToCourseForm* subForm = dynamic_cast<SubscriptionToCourseForm*>(form);
        if (subForm) {
            subForm->setSubscriptionDetails(this, course);
        }
    }
    return form;
}