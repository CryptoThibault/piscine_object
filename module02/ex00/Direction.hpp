#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include "Wheel.hpp"

class Direction {
public:
    Direction() {}

    void turn(float p_angle) {}
private:
    Wheel wheel[4];
};

#endif
