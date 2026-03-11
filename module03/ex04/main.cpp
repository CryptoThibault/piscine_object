#include "ILogger.hpp"
#include "FileLogger.hpp"
#include "OStreamLogger.hpp"
#include <vector>

int main() {
    std::vector<ILogger*> loggers;
    std::string messages[4] = {
        "Program started",
        "Initializing components",
        "Loading configuration",
        "Program finished successfully"
    };

    FileLogger fileLogger("log.txt");
    OStreamLogger osLogger(std::cout);
    loggers.push_back(&fileLogger);
    loggers.push_back(&osLogger);

    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < loggers.size(); ++j)
            loggers[j]->write(messages[i]);
    }

    return 0;
}
