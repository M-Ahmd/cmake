#include <iostream>

int main() {
#ifndef NDEBUG
    std::cout << "Debug build\n";
#else
    std::cout << "Release build\n";
#endif
    return 0;
}