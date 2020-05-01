#include <iostream>
#include "simpleCURL.h"

int main() {
    simpleCURL curl;
    std::cout << curl.curl("https://ipecho.net/plain") <<std::endl;
} 
