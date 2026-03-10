#include "Worker.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"
#include <iostream>

Worker::Worker() {
    coordonnee.x = 0;
    coordonnee.y = 0;
    coordonnee.z = 0;
    stat.level = 1;
    stat.exp = 0;
}

void Worker::addTool(Tool *t) {
    if (!t)
        return;
    if (t->getOwner() && t->getOwner() != this)
        t->getOwner()->removeTool(t);
    t->setOwner(this);
    tools.push_back(t);
}

void Worker::removeTool(Tool *t) {
    for (size_t i = 0; i < tools.size(); ++i) {
        if (tools[i] == t) {
            t->setOwner(0);
            tools.erase(tools.begin() + i);

            std::vector<Workshop*> workshopsCopy = workshops;
            for (size_t j = 0; j < workshopsCopy.size(); ++j)
                workshopsCopy[j]->releaseWorker(this);
            return;
        }
    }
}

void Worker::useTool(Tool *t) {
    if (!t)
        return;
    for (size_t i = 0; i < tools.size(); ++i) {
        if (tools[i] == t) {
            t->use();
            return;
        }
    }
}

void Worker::work() {
    std::cout << "Worker is working..." << std::endl;
}

void Worker::addWorkshop(Workshop* ws) {
    workshops.push_back(ws);
}

void Worker::removeWorkshop(Workshop* ws) {
    for (size_t i = 0; i < workshops.size(); ++i) {
        if (workshops[i] == ws) {
            workshops.erase(workshops.begin() + i);
            return;
        }
    }
}

std::vector<Tool*> Worker::getTools() const {
    return tools;
}

const Position& Worker::getCoordonnee() const {
    return coordonnee;
}

const Statistic& Worker::getStat() const {
    return stat;
}

void Worker::setCoordonnee(const Position& p) {
    coordonnee = p;
}

void Worker::setStat(const Statistic& s) {
    stat = s;
}