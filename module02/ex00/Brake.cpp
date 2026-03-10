#include "Brake.hpp"

Brake::Brake() {
    wheel = new Wheel();
}

Brake::Brake(const Brake& other) {
    wheel = new Wheel(*other.wheel);
}

Brake& Brake::operator=(const Brake& other) {
    if (this != &other) {
        delete wheel;
        wheel = new Wheel(*other.wheel);
    }
    return *this;
}

Brake::~Brake() {
    delete wheel;
}

void Brake::execute(float p_force) {}

void Brake::attackWheel(Wheel* p_wheel) {}
