#include <iostream>
#include "Graph.hpp"
#include "Vector2.hpp"

int main() {
    Graph g1;

    g1.addPoint(Vector2(0.0f, 0.0f));
    g1.addPoint(Vector2(2.0f, 2.0f));
    g1.addPoint(Vector2(4.0f, 2.0f));
    g1.addPoint(Vector2(2.0f, 4.0f));

    std::cout << "INITIAL\n" << g1 << std::endl;

    g1.removePoint(1);
    std::cout << "\nREMOVE\n" << g1 << std::endl;
    if (!g1.removePoint(10))
        std::cout << "Remove impossible" << std::endl;

    Graph g2 = g1;
    std::cout << "\nCOPY\n" << g2 << std::endl;

    Graph g3;
    g3 = g1;
    g3.addPoint(Vector2(7.0f, 8.0f));
    std::cout << "\nASSIGN\n" << g3 << std::endl;

    std::cout << "\nG1 EXIST\n" << g1 << std::endl;

    return 0;
}