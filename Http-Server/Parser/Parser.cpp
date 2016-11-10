//
// Created by kerno on 16-11-9.
//

#include "Parser.h"

void Parser::parseRequest(char *requestStr, Request &request) {
    string *requestString = new string(requestStr);
    unsigned int i = 0,j = 0;

    // parse the request method,request resource and Http version
    for(i = 0;i < requestString->size();i++)
    {
        if(requestString->at(i) == ' ' && j == 0)
        {
            request.setRequsetMethod(removeBlank(requestString->substr(j,i - j)));
            j = i;
        }
        if (requestString->at(i) == ' ' && j != 0)
        {
            request.setRequestResource(removeBlank(requestString->substr(j + 1,i - j)));
            j = i;
        }
        if(requestString->at(i) == '\n')
        {
            request.setProtocol(removeBlank(requestString->substr(j + 1,i - j)));
            j = i;
            break;
        }
    }

    //parse the headers
    pair<string,string> *header = new pair<string,string>();
    vector<pair<string,string>> *headers = new vector<pair<string,string>>;
    for(i = j + 1;i < requestString->size();i++)
    {
        if(requestString->at(i) == ':' && requestString->at(i + 1) == ' ')
        {
            header->first = removeBlank(requestString->substr(j + 1,j - i));
            j = i;
        }
        if(requestString->at(i) == '\n')
        {
            header->second = removeBlank(requestString->substr(j + 1,j - i));
            j = i;
            headers->push_back(*header);
        }
    }
}

void Parser::parseResponse(char *responseStr, Response &response) {

}

string Parser::removeBlank(string str) {
    for(string::iterator it = str.begin();it != str.end();it++)
    {
        if(*it == '\n' || *it == '\r')
        {
            str.erase(it);
        }
    }
    return str;
}
