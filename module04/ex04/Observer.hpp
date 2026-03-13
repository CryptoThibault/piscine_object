#ifndef OBSERVER_HPP
#define OBSERVER_HPP

enum class Event
{
	RingBell
};

class Observer
{
public:
	virtual ~Observer() {}
    virtual void update(Event e, bool pause) = 0;
};

#endif