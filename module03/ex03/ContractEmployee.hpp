#ifndef CONTRACTEMPLOYEE_HPP
#define CONTRACTEMPLOYEE_HPP

#include "Employee.hpp"

class ContractEmployee : public Employee {
public:
    ContractEmployee(double hv) : Employee(hv), absentHours(0) {}

    void registerAbsence(int h) { absentHours += h; }

    int executeWorkday() {
        int worked = 7 - absentHours;
        if (worked < 0)
            worked = 0;
        absentHours = 0;
        return worked;
    }
private:
    int absentHours;
};
#endif
