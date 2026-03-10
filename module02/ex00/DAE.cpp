#include "DAE.hpp"

DAE::DAE() {
    direction = new Direction();
}

DAE::DAE(const DAE& other) {
    direction = new Direction(*other.direction);
}

DAE& DAE::operator=(const DAE& other) {
    if (this != &other) {
        delete direction;
        direction = new Direction(*other.direction);
    }
    return *this;
}

DAE::~DAE() {
    delete direction;
}

void DAE::use(float p_angle) {}