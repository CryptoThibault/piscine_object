#ifndef CAR_HPP
#define CAR_HPP

#include "BrakeController.hpp"
#include "Direction.hpp"
#include "Transmission.hpp"
#include "Motor.hpp"
#include "Electronics.hpp"
#include "Cockpit.hpp"

class Car {
private:
    BrakeController brakeController;
    Direction direction;
    Transmission transmission;
    Motor motor;
    Electronics electronics;
    Cockpit cockpit;
};

#endif
