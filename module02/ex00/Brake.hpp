#ifndef BRAKE_HPP
#define BRAKE_HPP

#include "Wheel.hpp"

class Brake {
public:
    Brake();
    Brake(const Brake& other);
    Brake& operator=(const Brake& other);
    ~Brake();

    void execute(float p_force);
    void attackWheel(Wheel* p_wheel);
private:
    Wheel* wheel;
};

#endif
