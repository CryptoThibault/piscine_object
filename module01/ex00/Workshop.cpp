#include "Workshop.hpp"
#include "Worker.hpp"

void Workshop::registerWorker(Worker* w) {
    if (!w)
        return;
    for (size_t i = 0; i < workers.size(); ++i)
        if (workers[i] == w)
            return;
    workers.push_back(w);
    w->addWorkshop(this);
}

void Workshop::releaseWorker(Worker* w) {
    if (!w)
        return;
    for (size_t i = 0; i < workers.size(); ++i) {
        if (workers[i] == w) {
            workers.erase(workers.begin() + i);
            w->removeWorkshop(this);
            return;
        }
    }
}

void Workshop::executeWorkDay() {
    for (size_t i = 0; i < workers.size(); ++i)
        workers[i]->work();
}

const std::vector<Worker*>& Workshop::getWorkers() const {
    return workers;
}