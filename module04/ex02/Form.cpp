#include "Form.hpp"
#include "Room.hpp"
#include "Singletons.hpp"
#include "Course.hpp"
#include "Student.hpp"

void CourseFinishedForm::execute() {
    if (!isValidated()) return;
    if (_course && _course->getResponsable()) {
        _course->getResponsable()->closeCourse();
    }
}

void NeedMoreClassRoomForm::execute() {
    if (!isValidated()) return;
    Room* r = new Room(_roomId);
    Singletons<Room>::getInstance().add(r);
}

void NeedCourseCreationForm::execute() {
    if (!isValidated()) return;
    Course* c = new Course(_courseName);
    c->assign(_professor);
    c->setNumberOfClassToGraduate(_numClass);
    c->setMaximumNumberOfStudent(_maxStudents);
    Singletons<Course>::getInstance().add(c);
}

void SubscriptionToCourseForm::execute() {
    if (!isValidated()) return;
    if (_student && _course) {
        _course->subscribe(_student);
        _student->subscribeToCourse(_course);
    }
}