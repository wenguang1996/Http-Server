//
// Created by kerno on 16-11-8.
//

#include "Response.h"

Response::Response() {
    headers = new vector<pair<string,string>>;
}
Response::~Response() {
    delete(headers);
}
vector<pair<string,string>> *Response::getHeaders() {

    return this->headers;
}

bool Response::setHeader(string header, string value) {

    if(header == " " || header == "\n")
    {
        return false;
    }
    vector<pair<string,string>>::iterator it,head = headers->begin(),tail = headers->end();
    pair<string,string> key(header,value);
    find(head,tail,key);
    if(it != tail)
    {
        key.second = value;
        return true;
    }
    else
    {
        pair<string,string> head(header,value);
        headers->push_back(head);
        return true;

    }

}
