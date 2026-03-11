#include "EmployeeManager.hpp"
#include "TempWorker.hpp"
#include "ContractEmployee.hpp"
#include "Apprentice.hpp"

int main() {
    EmployeeManager manager;

    TempWorker* t1 = new TempWorker(20);
    ContractEmployee* c1 = new ContractEmployee(25);
    Apprentice* a1 = new Apprentice(15);

    manager.addEmployee(t1);
    manager.addEmployee(c1);
    manager.addEmployee(a1);

    t1->mobilize(5);
    c1->registerAbsence(2);
    a1->registerAbsence(1);
    a1->goToSchool(4);

    manager.executeWorkday();
    manager.calculatePayroll();

    manager.removeEmployee(c1);

    t1->mobilize(3);
    a1->registerAbsence(0);
    a1->goToSchool(2);

    manager.executeWorkday();
    manager.calculatePayroll();

    delete t1;
    delete c1;
    delete a1;

    return 0;
}