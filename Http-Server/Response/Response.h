//
// Created by kerno on 16-11-8.
//

#ifndef HTTP_SERVER_RESPONSE_H
#define HTTP_SERVER_RESPONSE_H

#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Response {
public:
    inline Response(){
        headers = new vector<pair<string,string>>;
    }
    inline ~Response(){
        delete(headers);
    }
    ///to set headers value
    /// \param http response header
    /// \param header's value
    /// \return
    bool setHeader(string header,string value);
    ///
    /// \return all setted headers
    vector<pair<string,string>> *getHeaders();
private:
    vector<pair<string,string>> *headers;

};


#endif //HTTP_SERVER_RESPONSE_H
