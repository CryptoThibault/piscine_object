#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"
#include <cmath>

class Triangle : public Shape {
public:
    Triangle(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}

    double area() const {
        double s = perimeter() / 2;
        
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const { return a + b + c; }
private:
    double a, b, c;
};

#endif
