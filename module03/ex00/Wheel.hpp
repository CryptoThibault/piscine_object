#ifndef WHEEL_HPP
#define WHEEL_HPP

class Wheel {
public:
    Wheel() : angle(0) {}
    void turn_wheel(int a) {
        if (a >= -90 && a < 90)
            angle = a;
    }
    void straighten_wheels() { angle = 0; }

    int getAngle() const { return angle; }
private:
    int angle;
};

#endif