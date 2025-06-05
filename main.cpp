/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork1
*/

#include "Rotatebmp.hpp"
#include "structs.hpp"
#include <chrono>
#include <iostream>

int main() {
    Rotatebmp a;
    a.rotate_clockwise();
    a.show();
    a.clear();
    a.rotate_counterclw();
    a.show();
    a.clear();
    a.rotate_clockwise();
    a.create_kernel();
    
    auto start = std::chrono::high_resolution_clock::now();
    a.apply_gaussian_blur();
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()
              << " ms\n";
    
    a.show();
    a.clear();
    return 1;
}
