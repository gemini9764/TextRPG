#pragma once
#include <string>
#include <fstream>

class Logger
{
private:
    std::ofstream logFile;
    static Logger* instance;

    Logger();
    
public:
    ~Logger();
    static Logger& getInstance();
    void log(const std::string& message);
};
