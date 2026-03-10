#include "SteerWheel.hpp"

SteerWheel::SteerWheel() {
    dae = new DAE();
}

SteerWheel::SteerWheel(const SteerWheel& other) {
    dae = new DAE(*other.dae);
}

SteerWheel& SteerWheel::operator=(const SteerWheel& other) {
    if (this != &other) {
        delete dae;
        dae = new DAE(*other.dae);
    }
    return *this;
}

SteerWheel::~SteerWheel() {
    delete dae;
}

void SteerWheel::turn(float p_angle) {}
