#ifndef APPRENTICE_HPP
#define APPRENTICE_HPP

#include "Employee.hpp"

class Apprentice : public Employee {
public:
    Apprentice(int hv) : Employee(hv), schoolHours(0) {}

    void registerAbsence(int h) { absentHours += h; }
    void goToSchool(int h) { schoolHours += h; }

    int executeWorkday() {
        int worked = 7 - absentHours;
        if (worked < 0) worked = 0;
        int totalHours = worked + (schoolHours / 2);
        absentHours = 0;
        schoolHours = 0;
        return totalHours;
    }

private:
    int absentHours;
    int schoolHours;
};

#endif
