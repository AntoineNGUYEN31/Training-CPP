#include <iostream>
#include "myMath.h"

int main() {
    float res=addition(4.1,5.);
    //std::cout << res <<std::endl;
    if ((res-9.1)<0.01){
      std::cout << 0 <<std::endl;
    }else{
      std::cout << 1 <<std::endl;
    }
} 
