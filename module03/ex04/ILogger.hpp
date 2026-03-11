#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <iostream>
#include <ctime>

class LoggerUtils {
public:
    static std::string getCurrentTime() {
        std::time_t now = std::time(NULL);
        char buf[20];
        std::strftime(buf, sizeof(buf), "%H:%M:%S", std::localtime(&now));
        return std::string(buf);
    }
};

class ILogger {
public:
    virtual ~ILogger() {}

    std::string getCurrentTime() {
        std::time_t now = std::time(NULL);
        char buf[20];
        std::strftime(buf, sizeof(buf), "%H:%M:%S", std::localtime(&now));
        return std::string(buf);
    }

    virtual void write(std::string) = 0;
};

#endif
