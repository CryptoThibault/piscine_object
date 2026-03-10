#ifndef SINGLETON_HPP
#define SINGLETON_HPP

template <typename T>
class Singleton {
protected:
    Singleton() {}
    ~Singleton() {}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
public:
    static T* getInstance() {
        static T instance;
        return &instance;
    }
};
#endif
