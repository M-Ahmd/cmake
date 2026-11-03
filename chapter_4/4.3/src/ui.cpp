#include "ui.h"
#include <iostream>

void Ui::render() {
    int result = addNumbers(5, 10);
    std::cout << "Rendering UI... Math Result = " << result << "\n";
}