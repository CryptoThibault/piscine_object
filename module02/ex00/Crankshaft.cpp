#include "Crankshaft.hpp"

Crankshaft::Crankshaft() {
    transmission = new Transmission();
}

Crankshaft::Crankshaft(const Crankshaft& other) {
    transmission = new Transmission(*other.transmission);
}

Crankshaft& Crankshaft::operator=(const Crankshaft& other) {
    if (this != &other) {
        delete transmission;
        transmission = new Transmission(*other.transmission);
    }
    return *this;
}

Crankshaft::~Crankshaft() {
    delete transmission;
}

void Crankshaft::activate(float p_force) {}