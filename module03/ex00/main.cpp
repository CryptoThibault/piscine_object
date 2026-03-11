#include "Car.hpp"

int main() {
    Car car;

    std::cout << "[0]" << car << std::endl;

    car.start();
    car.shift_gears_up();
    car.accelerate(20);

    std::cout << "[1]" << car << std::endl;

    car.shift_gears_up();
    car.accelerate(10);
    car.turn_wheel(45);

    std::cout << "[2]" << car << std::endl;

    car.straighten_wheels();
    car.apply_force_on_brakes(50);
    car.accelerate(-20);
    car.shift_gears_down();

    std::cout << "[3]" << car << std::endl;

    car.apply_emergency_brakes();
    car.accelerate(-10);
    car.shift_gears_down();
    
    std::cout << "[4]" << car << std::endl;

    car.apply_force_on_brakes(0);
    car.reverse();
    car.accelerate(5);
    
    std::cout << "[5]" << car << std::endl;

    car.accelerate(-5);
    car.reverse();
    car.stop();

    std::cout << "[6]" << car << std::endl;

    return 0;
}
