#include "Singletons.hpp"
#include "Room.hpp"
#include "Course.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "Form.hpp"
#include "Secretary.hpp"
#include "Headmaster.hpp"
#include <iostream>

int main() {
    Secretary secretary("McGonagall");
    Headmaster headmaster("Dumbledore");
    Professor prof("Snape");
    Course course("Potions");
    Student student("Harry");

    course.assign(&prof);

    std::cout << "[CourseFinishedForm]" << std::endl;
    Form* f1 = secretary.createForm(FormType::CourseFinished);
    secretary.setCourseFinishedForm(f1, &course);
    headmaster.receiveForm(f1);
    headmaster.validate(f1);
    f1->execute();
    secretary.archiveForm(f1);
    std::cout << std::endl;

    std::cout << "[NeedMoreClassRoomForm]" << std::endl;
    Form* f2 = secretary.createForm(FormType::NeedMoreClassRoom);
    secretary.setNeedMoreClassRoomForm(f2, 99);
    headmaster.receiveForm(f2);
    headmaster.validate(f2);
    f2->execute();
    secretary.archiveForm(f2);
    std::cout << "Room ID: " << Singletons<Room>::getInstance().get(0)->getID() << std::endl;
    std::cout << std::endl;

    std::cout << "[NeedCourseCreationForm]" << std::endl;
    Form* f3 = secretary.createForm(FormType::NeedCourseCreation);
    secretary.setNeedCourseCreationForm(f3, "Defense Against Dark Arts", &prof, 10, 20);
    headmaster.receiveForm(f3);
    headmaster.validate(f3);
    f3->execute();
    secretary.archiveForm(f3);
    std::cout << "Course Name: " << Singletons<Course>::getInstance().get(0)->getName() << std::endl;
    std::cout << std::endl;

    std::cout << "[SubscriptionToCourseForm]" << std::endl;
    Form* f4 = secretary.createForm(FormType::SubscriptionToCourse);
    secretary.setSubscriptionToCourseForm(f4, &student, &course);
    headmaster.receiveForm(f4);
    headmaster.validate(f4);
    f4->execute();
    secretary.archiveForm(f4);
    std::cout << "Harry Course: " << student.getSubscribedCourses()[0]->getName() << std::endl;
    std::cout << std::endl;

    std::cout << "[Unvalidated CourseFinishedForm]" << std::endl;
    Form* f5 = secretary.createForm(FormType::CourseFinished);
    secretary.setCourseFinishedForm(f5, &course);
    headmaster.receiveForm(f5);
    f5->execute();
    secretary.archiveForm(f5);
    std::cout << std::endl;

    SecretarialOffice* office = Singletons<SecretarialOffice>::getInstance().get(0);
    std::cout << "Archived forms count: " << office->getArchivedForms().size() << std::endl;

    return 0;
}