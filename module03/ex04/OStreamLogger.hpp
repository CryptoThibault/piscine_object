#ifndef OSTREAMLOGGER_HPP
#define OSTREAMLOGGER_HPP

#include "ILogger.hpp"

class OStreamLogger : public ILogger {
private:
    std::ostream& out;

public:
    OStreamLogger(std::ostream& output) : out(output) {}

    void write(std::string message) {
        out << "[" << LoggerUtils::getCurrentTime() << "] " << message << std::endl;
    }
};

#endif
