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
    auto& students = Singletons<Student>::getInstance();
    auto& professors = Singletons<Professor>::getInstance();

    students.add(new Student("Harry"));
    students.add(new Student("Hermione"));

    professors.add(new Professor("Rogue"));

    Secretary secretary("McGonagall");
    Headmaster headmaster("Dumbledore", &secretary);

    headmaster.ringBell();

    for (size_t i = 0; i < students.size(); ++i)
        std::cout << "Student " << i << " paused = " << students.get(i)->isPaused() << "\n";

    for (size_t i = 0; i < professors.size(); ++i)
        std::cout << "Professor " << i << " paused = " << professors.get(i)->isPaused() << "\n";

    headmaster.ringBell();

    for (size_t i = 0; i < students.size(); ++i)
        std::cout << "Student " << i << " paused = " << students.get(i)->isPaused() << "\n";

    for (size_t i = 0; i < professors.size(); ++i)
        std::cout << "Professor " << i << " paused = " << professors.get(i)->isPaused() << "\n";

}