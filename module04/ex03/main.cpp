#include "Singletons.hpp"
#include "Room.hpp"
#include "Course.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "Form.hpp"
#include "Secretary.hpp"
#include "Headmaster.hpp"
#include <iostream>

int main()
{
    Secretary* secretary = new Secretary("McGonagall");
    Headmaster* headmaster = new Headmaster("Dumbledore", secretary);
    Professor* prof = new Professor("Snape");
    Student* student = new Student("Harry");

    Singletons<Headmaster>::getInstance().add(headmaster);
    Singletons<SecretarialOffice>::getInstance().add(new SecretarialOffice());
    Singletons<Professor>::getInstance().add(prof);

    std::cout << "[NeedCourseCreationForm via Professor]" << std::endl;
    Form* courseForm = prof->requestCourseCreation("Potions", 3, 20);
    headmaster->validate(courseForm);
    courseForm->execute();
    secretary->archiveForm(courseForm);
    std::cout << "Course Name: " << Singletons<Course>::getInstance().get(0)->getName() << std::endl;
    std::cout << std::endl;

    Course* course = Singletons<Course>::getInstance().get(0);

    prof->assignCourse(course);

    std::cout << "[SubscriptionToCourseForm via Student]" << std::endl;
    Form* subForm = student->requestCourseSubscription(headmaster, course);
    headmaster->validate(subForm);
    subForm->execute();
    secretary->archiveForm(subForm);
    std::cout << "Harry's Course: " << student->getSubscribedCourses()[0]->getName() << std::endl;
    std::cout << std::endl;

    std::cout << "[Test: Require Professors to do class and create class]" << std::endl;
    std::cout << "Harry's classes attended before: " << student->getProgress(course) << std::endl;
    std::cout << "Classroom nb before: " << Singletons<Classroom>::getInstance().size() << std::endl;
    headmaster->requireProfessors();
    std::cout << "Professors have done class." << std::endl;
    std::cout << "Harry's classes attended after: " << student->getProgress(course) << std::endl;
    std::cout << "Classroom nb before: " <<  Singletons<Classroom>::getInstance().size() << std::endl;
    std::cout << std::endl;

    Classroom* classroom = new Classroom(99);
    Singletons<Classroom>::getInstance().add(classroom);
    classroom->assignCourse(course);

    std::cout << "[Student attends class]" << std::endl;
    if (student->attendClass(classroom)) {
        std::cout << "Student is ready to graduate, professor requests graduation" << std::endl;
        Form* gradForm = prof->requestStudentGraduation(student, course);
        headmaster->validate(gradForm);
        gradForm->execute();
        secretary->archiveForm(gradForm);
    } else {
        std::cout << "Student attended class but not ready to graduate yet" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "[Student attends class again]" << std::endl;
    if (student->attendClass(classroom)) {
        std::cout << "Student is ready to graduate, professor requests graduation" << std::endl;
        Form* gradForm = prof->requestStudentGraduation(student, course);
        headmaster->validate(gradForm);
        gradForm->execute();
        secretary->archiveForm(gradForm);
    } else {
        std::cout << "Student attended class but not ready to graduate yet" << std::endl;
    }
    std::cout << std::endl;

    SecretarialOffice* office = Singletons<SecretarialOffice>::getInstance().get(0);
    std::cout << "Archived forms count: " << office->getArchivedForms().size() << std::endl;

    return 0;
}
