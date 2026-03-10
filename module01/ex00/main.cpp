#include <iostream>
#include "Worker.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"

int main() {
    std::cout << "=== COMPOSITION ===\n";
    Worker w1;

    Position pos;
    pos.x = 10; pos.y = 20; pos.z = 5;
    w1.setCoordonnee(pos);

    Statistic stat;
    stat.level = 5;
    stat.exp = 120;
    w1.setStat(stat);

    Position p = w1.getCoordonnee();
    Statistic s = w1.getStat();
    std::cout << "Position: (" << p.x << ", " << p.y << ", " << p.z << ")\n";
    std::cout << "Stat: level=" << s.level << ", exp=" << s.exp << "\n";

    std::cout << "\n=== AGGREGATION ===\n";
    Shovel shovel;
    Hammer hammer;
    Worker w2;
    Worker w3;
    w2.addTool(&shovel);
    w2.addTool(&hammer);
    std::cout << "w2 uses tools:\n";
    for (size_t i = 0; i < w2.getTools().size(); ++i) {
        w2.getTools()[i]->use();
        std::cout << "numberOfUses = " << w2.getTools()[i]->getNumberOfUses() << "\n";
    }

    w3.addTool(&hammer);
    std::cout << "w3 uses tools:\n";
    for (size_t i = 0; i < w3.getTools().size(); ++i) {
        w3.getTools()[i]->use();
        std::cout << "numberOfUses = " << w3.getTools()[i]->getNumberOfUses() << "\n";
    }

    std::cout << "w2 tools after transfer:\n";
    for (size_t i = 0; i < w2.getTools().size(); ++i) {
        w2.getTools()[i]->use();
        std::cout << "numberOfUses = " << w2.getTools()[i]->getNumberOfUses() << "\n";
    }

    std::cout << "\n=== INHERITANCE ===\n";
    Tool* tools[2];
    tools[0] = &shovel;
    tools[1] = &hammer;
    for (size_t i = 0; i < 2; ++i) {
        tools[i]->use();
        std::cout << "Tool use count = " << tools[i]->getNumberOfUses() << "\n";
    }

    w2.useTool(&shovel);
    std::cout << "Shovel numberOfUses after useTool = " << shovel.getNumberOfUses() << "\n";

    std::cout << "w2 tools before removal:\n";
    for (size_t i = 0; i < w2.getTools().size(); ++i) {
        std::cout << "Tool " << i << "\n";
    }
    w2.removeTool(&shovel);
    std::cout << "w2 tools after removal:\n";
    for (size_t i = 0; i < w2.getTools().size(); ++i) {
        std::cout << "Tool " << i << "\n";
    }

    std::cout << "\n=== ASSOCIATION ===\n";
    Workshop ws1, ws2;
    ws1.registerWorker(&w1);
    ws1.registerWorker(&w2);
    ws2.registerWorker(&w2);
    ws2.registerWorker(&w3);

    std::cout << "ws1 executes workday:\n";
    ws1.executeWorkDay();
    std::cout << "ws2 executes workday:\n";
    ws2.executeWorkDay();

    ws1.releaseWorker(&w2);
    std::cout << "ws1 executes workday after removal of w2:\n";
    ws1.executeWorkDay();

    const std::vector<Worker*>& wList = ws1.getWorkers();
    std::cout << "ws1 has " << wList.size() << " worker(s)\n";

    std::cout << "\n=== BONUS ===\n";
    Worker w4;
    w4.addTool(&shovel);
    w4.addTool(&hammer);

    Shovel* myShovel = w4.GetTool<Shovel>();
    if (myShovel)
        myShovel->use();

    Hammer* myHammer = w4.GetTool<Hammer>();
    if (myHammer)
        myHammer->use();

    Workshop ws3;
    ws3.registerWorker(&w4);
    std::cout << "ws3 has " << ws3.getWorkers().size() << " worker(s) before tool removal\n";
    w4.removeTool(&shovel);
    std::cout << "ws3 has " << ws3.getWorkers().size() << " worker(s) after tool removal\n";

    return 0;
}