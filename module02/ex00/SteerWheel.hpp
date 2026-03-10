#ifndef STEERWHEEL_HPP
#define STEERWHEEL_HPP

#include "DAE.hpp"

class SteerWheel {
public:
    SteerWheel();
    SteerWheel(const SteerWheel& other);
    SteerWheel& operator=(const SteerWheel& other);
    ~SteerWheel();

    void turn(float p_angle);
private:
    DAE* dae;
};

#endif
