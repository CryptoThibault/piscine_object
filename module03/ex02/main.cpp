#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include <iostream>

int main() {
    Rectangle rect(10, 5);
    Triangle tri(3, 4, 5);
    Circle circ(3);

    std::cout << "Rectangle:" << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;
    std::cout << "Area: " << rect.area() << "\n\n";

    std::cout << "Triangle:" << std::endl;
    std::cout << "Perimeter: " << tri.perimeter() << std::endl;
    std::cout << "Area: " << tri.area() << "\n\n";

    std::cout << "Circle:" << std::endl;
    std::cout << "Perimeter: " << circ.perimeter() << std::endl;
    std::cout << "Area: " << circ.area() << std::endl;

    return 0;
}