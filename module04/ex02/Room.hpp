#ifndef ROOM_HPP
#define ROOM_HPP

class Person;
class Course;
class Form;

class Room
{
private:
	long long ID;
	std::vector<Person*> _occupants;

public:
	Room(long long id) : ID(id) {}
	bool canEnter(Person*);
	void enter(Person*);
	void exit(Person*);
	
	void printOccupant();

	long long getID() const { return ID; }
};

class Classroom : public Room
{
private:
	Course* _currentCourse;

public:
	Classroom();
	void assignCourse(Course* p_course);
};

class HeadmasterOffice : public Room {};

class StaffRestRoom : public Room {};

class Courtyard : public Room {};

#endif
