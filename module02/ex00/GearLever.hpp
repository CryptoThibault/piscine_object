#ifndef GEARLEVER_HPP
#define GEARLEVER_HPP

#include "Singleton.hpp"
#include "Gear.hpp"

class GearLever : public Singleton<GearLever> {
public:
    void change() {}
    Gear* activeGear() {}
private:
    Gear gear[5];
    int level;
    friend class Singleton<GearLever>;
    GearLever() : level(0) {}
};

#endif
