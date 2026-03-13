#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Room;

class Person
{
private:
	std::string _name;
	Room* _currentRoom;
public:
	Person(const std::string& p_name) : _name(p_name) {}
	Room* room() { return (_currentRoom); }

	std::string getName() const { return _name; }
};

#endif
