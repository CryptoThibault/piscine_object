#ifndef WORKER_HPP
#define WORKER_HPP

#include <vector>
#include <cstddef>
#include "Position.hpp"
#include "Statistic.hpp"

class Tool;
class Workshop;

class Worker {
public:
    Worker();

    void addTool(Tool* t);
    void removeTool(Tool* t);
    void useTool(Tool* t);
    void work();
    void addWorkshop(Workshop* ws);
    void removeWorkshop(Workshop* ws);

    std::vector<Tool*> getTools() const;
    const Position& getCoordonnee() const;
    const Statistic& getStat() const;
    void setCoordonnee(const Position& p);
    void setStat(const Statistic& s);

    template <typename ToolType>
    ToolType* GetTool() {
        for (size_t i = 0; i < tools.size(); ++i) {
            ToolType* t = dynamic_cast<ToolType*>(tools[i]);
            if (t) return t;
        }
        return NULL;
    }
private:
    Position coordonnee;
    Statistic stat;
    std::vector<Tool*> tools;
    std::vector<Workshop*> workshops;
};

#endif
