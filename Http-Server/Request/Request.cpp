//
// Created by kerno on 16-11-8.
//

#include "Request.h"


Request::Request(const string &requsetMethod, const string &requestResource) : requsetMethod(requsetMethod),
                                                                               requestResource(requestResource) {
    headers = new vector<pair<string,string>>;
}

vector<pair<string, string>> *Request::getHeaders() const {
    return headers;
}

void Request::setHeaders(vector<pair<string, string>> *headers) {
    vector<pair<string,string>>::iterator it;
    for(it = headers->begin();it != headers->end();it++)
    {
        this->headers->push_back(*it);
    }
}

const string &Request::getRequsetMethod() const {
    return requsetMethod;
}

void Request::setRequsetMethod(const string &requsetMethod) {
    Request::requsetMethod = requsetMethod;
}

const string &Request::getRequestResource() const {
    return requestResource;
}

void Request::setRequestResource(const string &requestResource) {
    Request::requestResource = requestResource;
}

const string &Request::getProtocol() const {
    return protocol;
}

void Request::setProtocol(const string &protocol) {
    Request::protocol = protocol;
}

ostream &operator<<(ostream &os, const Request &request) {
    os << "headers: " << request.headers << " requsetMethod: " << request.requsetMethod << " requestResource: "
       << request.requestResource << " protocol: " << request.protocol;
    return os;
}


