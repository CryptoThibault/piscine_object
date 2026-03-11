#ifndef TEMPWORKER_HPP
#define TEMPWORKER_HPP

#include "Employee.hpp"

class TempWorker : public Employee
{
private:
    int registeredHours;

public:
    TempWorker(int hv) : Employee(hv), registeredHours(0) {}

    void registerHour() { registeredHours++; }
    void mobilize(int h) { registeredHours += h; }

    int executeWorkday() {
        int wh = registeredHours;
        registeredHours = 0;
        return wh;
    }
};

#endif
