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
    inline Request(){
        headers = new vector<pair<string,string>>;
    }

    inline ~Request(){
        delete(headers);
    }

    inline Request(const string &requsetMethod, const string &requestResource);

    vector<pair<string, string>> *getHeaders() const;

    void setHeaders(vector<pair<string, string>> *headers);

    const string &getRequsetMethod() const;

    void setRequsetMethod(const string &requsetMethod);

    const string &getRequestResource() const;

    void setRequestResource(const string &requestResource);

    friend ostream &operator<<(ostream &os, const Request &request);

    const string &getProtocol() const;

    void setProtocol(const string &protocol);

private:
    vector<pair<string,string>> *headers;

    string requsetMethod;

    string requestResource;

    string protocol;

};


#endif //HTTP_SERVER_REQUEST_H
