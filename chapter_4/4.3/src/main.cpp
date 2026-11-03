#include "ui.h"
#include "cache.hpp"

int main() {
    // 1. استخدام مكتبة Ui (والتي تستدعي Math بداخلها)
    Ui myUi;
    myUi.render();

    // 2. استخدام مكتبة Cache (والتي تستدعي Logger بداخلها)
    Cache<int> myCache;
    myCache.store(42);

    return 0;
}