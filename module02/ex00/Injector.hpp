#ifndef INJECTOR_HPP
#define INJECTOR_HPP

#include "LinkablePart.hpp"
#include "ExplosionChamber.hpp"

class Injector : public LinkablePart {
public:
    Injector();
    Injector(const Injector& other);
    Injector& operator=(const Injector& other);
    ~Injector();

    void execute(float p_pression);
private:
    ExplosionChamber *explosionChamber;
};

#endif
