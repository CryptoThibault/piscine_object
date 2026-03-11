#ifndef EMPLOYEEMANAGER_HPP
#define EMPLOYEEMANAGER_HPP

#include <iostream>
#include <vector>
#include "Employee.hpp"

class Employee;

class EmployeeManager {
public:
    void addEmployee(Employee* e) {
        employees.push_back(e);
    }

    void removeEmployee(Employee* e) {
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i] == e) {
                employees.erase(employees.begin() + i);
                break;
            }
        }
    }

    void executeWorkday() {
        for (size_t i = 0; i < employees.size(); ++i) {
            int hours = employees[i]->executeWorkday();
            employees[i]->setHoursWorked(employees[i]->getHoursWorked() + hours);
        }
    }

    void  calculatePayroll() {
        std::cout << "---- Payroll ----" << std::endl;
        for (size_t i = 0; i < employees.size(); ++i) {
            double salary = employees[i]->getHoursWorked() * employees[i]->getHourlyValue();
            std::cout << "Employee " << i + 1 << ": " << employees[i]->getHoursWorked() 
                << " hours, Salary: " << salary << "$" << std::endl;
        }
    }

private:
    std::vector<Employee*> employees;
};

#endif
