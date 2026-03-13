#include "Secretary.hpp"
#include "Singletons.hpp"
#include "Room.hpp"

Form* Secretary::createForm(FormType p_formType) {
    switch (p_formType) {
        case FormType::CourseFinished:
            return new CourseFinishedForm();
        case FormType::NeedMoreClassRoom:
            return new NeedMoreClassRoomForm();
        case FormType::NeedCourseCreation:
            return new NeedCourseCreationForm();
        case FormType::SubscriptionToCourse:
            return new SubscriptionToCourseForm();
        case FormType::GraduateStudent:
            return new GraduateStudentForm();
    }
    return nullptr;
}

void Secretary::archiveForm(Form* f) {
    if (!f)
        return;
    SecretarialOffice* office = Singletons<SecretarialOffice>::getInstance().get(0);
    if (!office) {
        office = new SecretarialOffice();
        Singletons<SecretarialOffice>::getInstance().add(office);
    }
    office->archiveForm(f);
}

