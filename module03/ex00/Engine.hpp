#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine {
public:
    Engine() : running(false) {}
    void start() { running = true; }
    void stop() { running = false; }

    bool isRunning() const { return running; }
private:
    bool running;
};

#endif