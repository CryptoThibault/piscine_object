#ifndef CAR_HPP
#define CAR_HPP

#include "Engine.hpp"
#include "Gear.hpp"
#include "Wheel.hpp"
#include "BrakeController.hpp"
#include <iostream>

class Car {
public:
    Car() : speed(0) {}
    void start() { engine.start(); }
    void stop() { engine.stop(); }
    void accelerate(int s) { speed += s; }
    void shift_gears_up() { gear.shift_gears_up(); }
    void shift_gears_down() { gear.shift_gears_down(); }
    void reverse() { gear.reverse(); }
    void turn_wheel(int angle) { wheel.turn_wheel(angle); }
    void straighten_wheels() { wheel.straighten_wheels(); }
    void apply_force_on_brakes(int force) { brakeController.apply_force_on_brakes(force); }
    void apply_emergency_brakes() { brakeController.apply_emergency_brakes(); }

    int getSpeed() const { return speed; }

    friend std::ostream& operator<<(std::ostream& os, const Car& car);
private:
    int speed;
    Engine engine;
    Gear gear;
    Wheel wheel;
    BrakeController brakeController;
};


inline std::ostream& operator<<(std::ostream& os, const Car& car)
{
    os << "Car info:\n";
    os << "Speed: " << car.speed << "\n";
    os << "Engine running: " << (car.engine.isRunning() ? "yes" : "no") << "\n";
    os << "Gear level: " << car.gear.getLevel() << "\n";
    os << "Reverse gear: " << (car.gear.isReverse() ? "yes" : "no") << "\n";
    os << "Wheel angle: " << car.wheel.getAngle() << "\n";
    os << "Brake controller force: " << car.brakeController.getForce() << "\n";

    return os;
}

#endif
