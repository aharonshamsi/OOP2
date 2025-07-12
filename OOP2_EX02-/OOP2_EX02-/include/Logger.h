#pragma once
// Logger.h - Handles System Logging
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>
#include <ctime>
#include <iostream>

// מחלקה לטיפול בהדפסות של כל הממשק
class Logger {
private:
    static Logger* instance;
    static std::mutex mutex;
    std::ofstream logFile;
    Logger(); // Private constructor to prevent direct instantiation

public:
    static Logger* getInstance();
    void log(const std::string& message);
    ~Logger();
};

#endif // LOGGER_H