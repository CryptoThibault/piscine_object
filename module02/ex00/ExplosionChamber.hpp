#ifndef EXPLOSIONCHAMBER_HPP
#define EXPLOSIONCHAMBER_HPP

#include "Crankshaft.hpp"

class ExplosionChamber {
public:
    ExplosionChamber();
    ExplosionChamber(const ExplosionChamber& other);
    ExplosionChamber& operator=(const ExplosionChamber& other);
    ~ExplosionChamber();

    void fill(float p_volume);
private:
    Crankshaft* crankshaft;
};

#endif
