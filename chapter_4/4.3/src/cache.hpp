#pragma once
#include "logger.h" // الاعتماد على Logger

template <typename T>
class Cache {
public:
    void store(T item) {
        logMessage("Item stored in cache.");
    }
};