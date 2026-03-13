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

void Secretary::setCourseFinishedForm(Form* f, Course* course) {
    if (!f || !course) return;
    CourseFinishedForm* cf = dynamic_cast<CourseFinishedForm*>(f);
    if (cf) {
        cf->setCourse(course);
    }
}

void Secretary::setNeedMoreClassRoomForm(Form* f, long long roomId) {
    if (!f) return;
    NeedMoreClassRoomForm* nm = dynamic_cast<NeedMoreClassRoomForm*>(f);
    if (nm) {
        nm->setRoomId(roomId);
    }
}

void Secretary::setNeedCourseCreationForm(Form* f, std::string name, Professor* prof, int numClass, int maxStudents) {
    if (!f) return;
    NeedCourseCreationForm* nc = dynamic_cast<NeedCourseCreationForm*>(f);
    if (nc) {
        nc->setCourseDetails(name, prof, numClass, maxStudents);
    }
}

void Secretary::setSubscriptionToCourseForm(Form* f, Student* student, Course* course) {
    if (!f) return;
    SubscriptionToCourseForm* sc = dynamic_cast<SubscriptionToCourseForm*>(f);
    if (sc) {
        sc->setSubscriptionDetails(student, course);
    }
}
