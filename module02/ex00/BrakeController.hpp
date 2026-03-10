#ifndef BRAKECONTROLLER_HPP
#define BRAKECONTROLLER_HPP

#include "LinkablePart.hpp"

class BrakeController : public LinkablePart {
public:
    BrakeController() {}

    void execute(float p_pression) {}
private:
    Brake brake[4];
};

#endif
