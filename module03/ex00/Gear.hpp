#ifndef GEAR_HPP
#define GEAR_HPP

class Gear {
public:
    Gear() : level(0), reverseGear(false) {}
    void shift_gears_up() { 
        if (level < 6)
            level++;
    }
    void shift_gears_down() {
        if (level > 0)
            level--;
    }
    void reverse() { reverseGear = !reverseGear; }

    int getLevel() const { return level; }
    bool isReverse() const { return reverseGear; }
private:
    int level;
    bool reverseGear;
};

#endif