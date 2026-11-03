#include "logger.h"
#include <iostream>

void logMessage(const std::string& msg) {
    std::cout << "[LOG]: " << msg << "\n";
}