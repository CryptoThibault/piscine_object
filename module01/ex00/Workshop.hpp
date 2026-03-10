#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <vector>

class Worker;

class Workshop {
public:
    void registerWorker(Worker* w);
    void releaseWorker(Worker* w);
    void executeWorkDay();

    const std::vector<Worker*>& getWorkers() const;
private:
    std::vector<Worker*> workers;
};

#endif
