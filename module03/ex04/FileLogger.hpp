#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP

#include "ILogger.hpp"
#include <fstream>

class FileLogger : public ILogger{
public:
    FileLogger(const std::string& filename) {
        outFile.open(filename.c_str(), std::ios::app);
    }

    ~FileLogger() {
        if (outFile.is_open())
            outFile.close();
    }

    void write(std::string message) {
        if (outFile.is_open())
            outFile << "[" << LoggerUtils::getCurrentTime() << "] " << message << std::endl;
    }
private:
    std::ofstream outFile;
};

#endif
