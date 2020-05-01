#include <iostream>
#include <string>
#include "myIP.h"

#include <curl/curl.h>

using namespace std;

//writer function required to write curl reponse to string buffer
static int writer(char *data, size_t size, size_t nmemb,
                  std::string *writerData)
{
  if(writerData == NULL)
    return 0;
 
  writerData->append(data, size*nmemb);
 
  return size * nmemb;
}

string myIP::getRouterIP(){
  string URL="http://ipecho.net/plain"; 
  string res="ERROR";

  CURL *conn = NULL;
  static string buffer;
  CURLcode code;

  //init connection
  curl_global_init(CURL_GLOBAL_DEFAULT);
  conn= curl_easy_init();

  //set curl option
  code = curl_easy_setopt(conn, CURLOPT_URL, URL.c_str());
  code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
  code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer);

  //perform real curl
  code = curl_easy_perform(conn);
  
  return buffer;

}
