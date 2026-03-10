#ifndef DAE_HPP
#define DAE_HPP

#include "Direction.hpp"

class DAE {
public:
    DAE();
    DAE(const DAE& other);
    DAE& operator=(const DAE& other);
    ~DAE();

    void use(float p_angle);
private:
    Direction* direction;
};

#endif
