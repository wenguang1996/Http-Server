//
// Created by kerno on 16-11-8.
//

#include "Response.h"

vector<pair<string,string>> *Response::getHeaders() {

    return this->headers;
}

bool Response::setHeader(string header, string value) {

    if(header == " " || header == "\n")
    {
        return false;
    }
    bool isExist = false;
    vector<pair<string,string>>::iterator it;
    pair<string,string> key(header,value);
    for(it = headers->begin();it != headers->end();it++)
    {
        if(it->first == header)
        {
            it->second = value;
            isExist = true;
        }
    }
    if(!isExist)
    {
        pair<string,string> head(header,value);
        headers->push_back(head);
        return true;

    }

}
