#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "Injector.hpp"
#include "ExplosionChamber.hpp"
#include "Crankshaft.hpp"

class Motor {
public:
    Motor() {}

    void connectToTransmission(Transmission* p_transmission) {}
private:
    Injector injector;
    ExplosionChamber explosionChamber;
    Crankshaft crankshaft;
};

#endif
