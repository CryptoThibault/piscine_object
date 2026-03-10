#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP

#include <vector>
#include "Wheel.hpp"

class Transmission {
public:
    Transmission() {}

    void activate(float p_force) {}
private:
    std::vector<Wheel*> wheels;
};

#endif
