#ifndef SINGLETONS_HPP
#define SINGLETONS_HPP

#include <vector>
#include <cstddef>

template <typename T>
class Singletons {
private:
    std::vector<T*> list;

    Singletons() {}
    ~Singletons() {
        for (size_t i = 0; i < size(); ++i)
            delete list[i];
    }
public:
    static Singletons& getInstance()
    {
        static Singletons instance;
        return instance;
    }

    void add(T* item) { list.push_back(item); }
    T* get(size_t i) { return (i < list.size()) ? list[i] : nullptr; }
    size_t size() const { return list.size(); }
};

#endif
