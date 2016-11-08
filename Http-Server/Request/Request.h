//
// Created by kerno on 16-11-8.
//

#ifndef HTTP_SERVER_REQUEST_H
#define HTTP_SERVER_REQUEST_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Request {
public:
    inline Request();
    inline ~Request();
private:
    vector<pair<string,string>> *headers;
    string *requsetMethod;
    string *requestResource;

};


#endif //HTTP_SERVER_REQUEST_H
