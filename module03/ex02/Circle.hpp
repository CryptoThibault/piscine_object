#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#define PI 3.14159265358979323846

#include "Shape.hpp"

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}

    double area() const { return radius * radius * PI; }
    double perimeter() const { return radius * 2 * PI; }
private:
    double radius;
};

#endif
