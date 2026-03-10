#include "ExplosionChamber.hpp"

ExplosionChamber::ExplosionChamber() {
    crankshaft = new Crankshaft();
}

ExplosionChamber::ExplosionChamber(const ExplosionChamber& other) {
    crankshaft = new Crankshaft(*other.crankshaft);
}

ExplosionChamber& ExplosionChamber::operator=(const ExplosionChamber& other) {
    if (this != &other) {
        delete crankshaft;
        crankshaft = new Crankshaft(*other.crankshaft);
    }
    return *this;
}

ExplosionChamber::~ExplosionChamber() {
    delete crankshaft;
}

void ExplosionChamber::fill(float p_volume) {}
