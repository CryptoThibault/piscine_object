#include "Professor.hpp"
#include "Headmaster.hpp"
#include "Form.hpp"
#include "Singletons.hpp"
#include "Student.hpp"
#include "Room.hpp"

Form* Professor::requestCourseCreation(const std::string& name, int numClass, int maxStudents) {
    Form* form = nullptr;
    Headmaster* headmaster = Singletons<Headmaster>::getInstance().get(0);
    if (headmaster) {
        form = headmaster->requestForm(FormType::NeedCourseCreation);
        NeedCourseCreationForm* courseForm = dynamic_cast<NeedCourseCreationForm*>(form);
        if (courseForm) {
            courseForm->setCourseDetails(name, this, numClass, maxStudents);
        }
    }
    return form;
}

Form* Professor::requestStudentGraduation(Student* student, Course* course) {
    Form* form = nullptr;
    Headmaster* headmaster = Singletons<Headmaster>::getInstance().get(0);
    if (headmaster) {
        form = headmaster->requestForm(FormType::GraduateStudent);
        GraduateStudentForm* gradForm = dynamic_cast<GraduateStudentForm*>(form);
        if (gradForm) {
            gradForm->setGraduationDetails(student, course);
        }
    }
    return form;
}

void Professor::doClass() {
    Classroom* classroom = nullptr;
    auto& classrooms = Singletons<Classroom>::getInstance();
    for (size_t i = 0; i < classrooms.size(); ++i) {
        if (!classrooms.get(i)->getCurrentCourse()) {
            classroom = classrooms.get(i);
            break;
        }
    }
    if (!classroom) {
        classroom = new Classroom(classrooms.size());
        classrooms.add(classroom);
    }
    classroom->assignCourse(_currentCourse);
    std::vector<Student*> students = _currentCourse->getStudents();
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i]->attendClass(classroom))
            requestStudentGraduation(students[i], _currentCourse);
    }
}