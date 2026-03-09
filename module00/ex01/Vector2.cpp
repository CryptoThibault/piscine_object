#include "Vector2.hpp"

Vector2::Vector2(float px, float py) : x(px), y(py) {}

Vector2::Vector2(const Vector2& other) : x(other.x), y(other.y) {}

Vector2& Vector2::operator=(const Vector2& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2::~Vector2() {}

float Vector2::getX() const {
    return x;
}

float Vector2::getY() const {
    return y;
}

void Vector2::setX(float px) {
    x = px;
}

void Vector2::setY(float py) {
    y = py;
}