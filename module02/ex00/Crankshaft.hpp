#ifndef CRANKSHAFT_HPP
#define CRANKSHAFT_HPP

#include "Transmission.hpp"

class Crankshaft {
public:
    Crankshaft();
    Crankshaft(const Crankshaft& other);
    Crankshaft& operator=(const Crankshaft& other);
    ~Crankshaft();

    void activate(float p_force);
private:
    Transmission* transmission;
};

#endif
