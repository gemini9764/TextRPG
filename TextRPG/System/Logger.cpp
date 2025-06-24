#include "Logger.h"
#include <iostream>
#include <ctime>

Logger* Logger::instance = nullptr;

Logger::Logger()
{
    logFile.open("GameLog.txt", std::ios::app);
    if (!logFile)
    {
        std::cerr << "[Logger] Failed to open GameLog.txt\n";
    }
}

Logger::~Logger()
{
    if (logFile.is_open())
        logFile.close();
}

Logger& Logger::getInstance()
{
    if (!instance)
        instance = new Logger();

    return *instance;
}

void Logger::log(const std::string& message)
{
    if (logFile.is_open())
    {
        std::time_t now = std::time(nullptr);
        char timeBuffer[26];
        ctime_s(timeBuffer, sizeof(timeBuffer), &now);
        logFile << "[" << timeBuffer << "] " << message << "\n";
    }
}

