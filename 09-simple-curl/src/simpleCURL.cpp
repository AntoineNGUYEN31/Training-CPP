#include <iostream>
#include <string>
#include "simpleCURL.h"
#include <curl/curl.h>

//writer function required to write curl reponse to string buffer
static int writer(char *data, size_t size, size_t nmemb,
                  std::string *writerData)
{
  if(writerData == NULL)
    return 0;
 
  writerData->append(data, size*nmemb);
 
  return size * nmemb;
}

std::string simpleCURL::curl(std::string URL){

  CURL *conn = NULL;
  std::string buffer;
  CURLcode code;

  //init connection
  curl_global_init(CURL_GLOBAL_DEFAULT);
  conn= curl_easy_init();

  if(conn == NULL) {
    return "CURL ERROR";
  }

  //set curl option
  code = curl_easy_setopt(conn, CURLOPT_URL, URL.c_str());
  if(code != CURLE_OK) {
    return "CURL ERROR";
  }
  code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
  if(code != CURLE_OK) {
    return "CURL ERROR";
  }
  code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer);
  if(code != CURLE_OK) {
    return "CURL ERROR";
  }
  //perform real curl
  code = curl_easy_perform(conn);
  if(code != CURLE_OK) {
    return "CURL ERROR";
  }
  
  return buffer;

}
