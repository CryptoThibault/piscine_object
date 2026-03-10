#include "Pedal.hpp"

Pedal::Pedal() {
    linkablePart = new LinkablePart();
}

Pedal::Pedal(const Pedal& other) {
    linkablePart = new LinkablePart(*other.linkablePart);
}

Pedal& Pedal::operator=(const Pedal& other) {
    if (this != &other) {
        delete linkablePart;
        linkablePart = new LinkablePart(*other.linkablePart);
    }
    return *this;
}

Pedal::~Pedal() {
    delete linkablePart;
}

void Pedal::setTarget(LinkablePart* p_part) {}

void Pedal::use(float p_pression) {}