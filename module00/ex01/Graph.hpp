#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include "Vector2.hpp"

class Graph {
public:
    Graph();
    Graph(const Graph& other);
    Graph& operator=(const Graph& other);
    ~Graph();

    void addPoint(const Vector2& point);
    bool removePoint(size_t index);
    Vector2* getPoint(size_t index) const;

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
private:
    std::vector<Vector2*> points;
};

#endif
