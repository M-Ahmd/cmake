#include "math.hpp"
#include "logger.hpp" // استخدمنا Logger هنا سراً في ملف الـ cpp فقط

int addNumbers(int a, int b) {
    logMessage("addNumbers called.");
    return a + b;
}