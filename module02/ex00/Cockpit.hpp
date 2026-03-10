#ifndef COCKPIT_HPP
#define COCKPIT_HPP

#include "Pedal.hpp"
#include "SteerWheel.hpp"
#include "GearLever.hpp"

class Cockpit {
public:
    Pedal getPedal() { return pedal; }
    SteerWheel getSteerWheel() { return steerWheel; }
    GearLever getGearLever() { return gearLever; }
    void setPedal(Pedal p) { pedal = p }
    void setSteerWheel(SteerWheel sw) { steerWheel = sw }
    void setGearLever(GearLever gl) { gearLever = gl }
private:
    Pedal pedal;
    SteerWheel steerWheel;
    GearLever gearLever;
};

#endif
