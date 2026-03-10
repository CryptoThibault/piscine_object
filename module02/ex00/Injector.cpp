#include "Injector.hpp"

Injector::Injector() {
    explosionChamber = new ExplosionChamber();
}

Injector::Injector(const Injector& other) {
    explosionChamber = new ExplosionChamber(*other.explosionChamber);
}

Injector& Injector::operator=(const Injector& other) {
    if (this != &other) {
        delete explosionChamber;
        explosionChamber = new ExplosionChamber(*other.explosionChamber);
    }
    return *this;
}

Injector::~Injector() {
    delete explosionChamber;
}

void Injector::execute(float p_pression) {}
