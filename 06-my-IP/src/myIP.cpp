#include <iostream>
#include <string>
#include "myIP.h"

#include <simpleCURL.h>

using namespace std;

string myIP::getRouterIP(){
  string URL="http://ipecho.net/plain"; 
  simpleCURL curl;
  return curl.curl(URL);

}
