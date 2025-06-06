// Logger.cpp - Implements System Logging
#include "Logger.h"

Logger* Logger::instance = nullptr;
std::mutex Logger::mutex;

Logger::Logger() {
    logFile.open("system.log", std::ios::app);
    if (!logFile) {
        std::cerr << "Error: Unable to open log file." << std::endl;
    }
}

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = new Logger();
        }
    }
    return instance;
}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex);
    if (logFile) {
        std::time_t now = std::time(nullptr);
        char timeBuffer[26]; // Buffer for formatted time
        ctime_s(timeBuffer, sizeof(timeBuffer), &now);
        logFile << "[" << timeBuffer << "] " << message << std::endl;

    }
}

Logger::~Logger() {
    if (logFile) {
        logFile.close();
    }
}
