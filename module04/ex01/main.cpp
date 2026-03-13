#include <iostream>
#include "Singletons.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include "Room.hpp"
#include "Staff.hpp"

int main()
{
    Student* s1 = new Student("Harry");
    Student* s2 = new Student("Hermione");

    Course* c1 = new Course("Magic");
    Course* c2 = new Course("Flight");

    Room* r1 = new Room(12);
    Room* r2 = new Room(34);

    Staff* t1 = new Staff("Dumbledore");
    Staff* t2 = new Staff("Rogue");

    Singletons<Student>::getInstance().add(s1);
    Singletons<Student>::getInstance().add(s2);

    Singletons<Course>::getInstance().add(c1);
    Singletons<Course>::getInstance().add(c2);

    Singletons<Room>::getInstance().add(r1);
    Singletons<Room>::getInstance().add(r2);

    Singletons<Staff>::getInstance().add(t1);
    Singletons<Staff>::getInstance().add(t2);

    std::cout << "=== Students ===" << std::endl;
    for (size_t i = 0; i < Singletons<Student>::getInstance().size(); ++i)
        std::cout << Singletons<Student>::getInstance().get(i)->getName() << std::endl;

    std::cout << "=== Courses ===" << std::endl;
    for (size_t i = 0; i < Singletons<Course>::getInstance().size(); ++i)
        std::cout << Singletons<Course>::getInstance().get(i)->getName() << std::endl;

    std::cout << "=== Rooms ===" << std::endl;
    for (size_t i = 0; i < Singletons<Room>::getInstance().size(); ++i)
        std::cout << Singletons<Room>::getInstance().get(i)->getID() << std::endl;

    std::cout << "=== Staff ===" << std::endl;
    for (size_t i = 0; i < Singletons<Staff>::getInstance().size(); ++i)
        std::cout << Singletons<Staff>::getInstance().get(i)->getName() << std::endl;

    return 0;
}