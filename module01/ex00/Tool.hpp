#ifndef TOOL_HPP
#define TOOL_HPP

#include "Worker.hpp"

class Worker;

class Tool {
public:
    Tool() : numberOfUses(0), owner(0) {}
    virtual ~Tool() {}

    virtual void use() = 0;

    int getNumberOfUses() const { return numberOfUses; }
    Worker* getOwner() const { return owner; }
    void setNumberOfUses(int nb) { numberOfUses = nb; }
    void setOwner(Worker* w) { owner = w; }
private:
    int numberOfUses;
    class Worker* owner;
};

#endif
