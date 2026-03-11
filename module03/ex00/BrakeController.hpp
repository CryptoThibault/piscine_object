#ifndef BRAKECONTROLLER_HPP
#define BRAKECONTROLLER_HPP

#define MAX_FORCE 100

class BrakeController {
public:
    BrakeController() : force(0) {}
    void apply_force_on_brakes(int f) { force = f; }
    void apply_emergency_brakes() { force = MAX_FORCE; }

    int getForce() const { return force; }
private:
    int force;
};

#endif