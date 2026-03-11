#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const { return width * height; }
    double perimeter() const { return (width + height) * 2; }
private:
    double width;
    double height;
};

#endif
