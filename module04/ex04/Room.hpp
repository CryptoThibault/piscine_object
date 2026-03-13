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
	virtual ~Room() {}

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
	Classroom(long long id) : Room(id) {}
	void assignCourse(Course* p_course) { _currentCourse = p_course; }
	Course* getCurrentCourse() const { return _currentCourse; }
};

class StaffRestRoom : public Room {};

class Courtyard : public Room {};

#endif
