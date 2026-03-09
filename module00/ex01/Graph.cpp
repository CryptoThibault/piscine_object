#include "Graph.hpp"

Graph::Graph() {}

Graph::Graph(const Graph& other) {
    for (size_t i = 0; i < other.points.size(); i++)
        points.push_back(new Vector2(*other.points[i]));
}

Graph& Graph::operator=(const Graph& other) {
    if (this != &other) {
        for (size_t i = 0; i < points.size(); i++)
            delete points[i];
        points.clear();
        for (size_t i = 0; i < other.points.size(); i++)
            points.push_back(new Vector2(*other.points[i]));
    }
    return *this;
}

Graph::~Graph() {
    for (size_t i = 0; i < points.size(); i++)
        delete points[i];
    points.clear();
}

void Graph::addPoint(const Vector2& point) {
    points.push_back(new Vector2(point));
}

bool Graph::removePoint(size_t index) {
    if (index >= points.size())
        return false;
    delete points[index];
    points.erase(points.begin() + index);
    return true;
}

Vector2* Graph::getPoint(size_t index) const {
    if (index >= points.size())
        return NULL;
    return points[index];
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    const int WIDTH = 6;
    const int HEIGHT = 6;

    for (int y = HEIGHT - 1; y >= 0; --y) {
        os << y << " ";
        for (int x = 0; x < WIDTH; ++x) {
            bool found = false;
            for (size_t i = 0; i < graph.points.size(); ++i) {
                int px = static_cast<int>(graph.points[i]->getX());
                int py = static_cast<int>(graph.points[i]->getY());
                if (px == x && py == y) {
                    found = true;
                    break;
                }
            }
            os << (found ? "X" : ".") << " ";
        }
        os << std::endl;
    }

    os << "  ";
    for (int x = 0; x < WIDTH; ++x)
        os << x << " ";
    os << std::endl;

    return os;
}