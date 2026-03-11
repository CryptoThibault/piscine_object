#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Employee {
public:
    Employee(int hv) : hourlyValue(hv) {}
    virtual ~Employee() {}

    virtual int executeWorkday() = 0;

    int getHourlyValue() const { return hourlyValue; }
    int getHoursWorked() const { return hoursWorked; }
    void setHoursWorked(int h) { hoursWorked = h; }
private:
    int hourlyValue;
    int hoursWorked;
};

#endif
