#ifndef PEDAL_HPP
#define PEDAL_HPP

#include "LinkablePart.hpp"

class Pedal {
public:
    Pedal();
    Pedal(const Pedal& other);
    Pedal& operator=(const Pedal& other);
    ~Pedal();

    void setTarget(LinkablePart* p_part);
    void use(float p_pression);
private:
    LinkablePart* linkablePart;
};

#endif
