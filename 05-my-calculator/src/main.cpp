#include <iostream>
#include "myMath.h"

int main(void) {
    float x,y;
    std::cout << "Input x: ";
    std::cin >>x;
    std::cout << "Input y: ";
    std::cin >>y;

    std::cout << "x + y = " << addition(x,y) <<std::endl;
}
